#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <climits>
#include "poly.h"

using namespace std;
using namespace coen79_lab4;
    
namespace coen79_lab4
{
    // CONSTANTS
    const unsigned int polynomial::MAXIMUM_DEGREE;

    // CONSTRUCTOR
    polynomial::polynomial(double c, unsigned int exponent){
        assert(exponent <= MAXIMUM_DEGREE);
        for(int i = 0; i < MAXIMUM_DEGREE; i++) {
            coef[i] = 0;
        }
        coef[exponent] = c;
        current_degree = exponent; 
    }

     void polynomial::update_current_degree() {
        int point= 0;
        for(int i = 0; i < MAXIMUM_DEGREE; i++) {
            if(coef[i] != 0) {
                point = i;
            }
        }
        current_degree = point;
    }
    // MODIFICATION MEMBER FUNCTIONS
    void polynomial::assign_coef(double coefficient, unsigned int exponent) {
        assert(exponent <= MAXIMUM_DEGREE);
        coef[exponent] = coefficient;
        update_current_degree();
    }
    void polynomial::add_to_coef(double amount, unsigned int exponent){
        assert(exponent <= MAXIMUM_DEGREE);
        coef[exponent] += amount;
        update_current_degree();
    }
    void polynomial::clear( ) {
    for(int i = 0; i < MAXIMUM_DEGREE; i++) {
            coef[i] = 0;
        }
        update_current_degree();
    }
    
    // // CONSTANT MEMBER FUNCTIONS
    polynomial polynomial::antiderivative( ) const {
        assert(degree() < MAXIMUM_DEGREE);          // Need to check that highest non-zero coef exponent is smaller than 29
        polynomial a(0,0);                          // Create a temporary polynomial
        a.coef[0] = 0;                              // that is completely empty
        for(int i = 0; i < MAXIMUM_DEGREE; i++) {   // antiderivative is reversed chain rule
            a.coef[i+1] = (coef[i]/(i+1));
        }
        a.coef[0] = 0;
        a.update_current_degree();
        return a;
    }
    double polynomial::coefficient(unsigned int exponent) const {
        if(exponent > MAXIMUM_DEGREE)               // If exponent over 29, then return 0
            return 0;
        else
            return coef[exponent]; 
    }
    double polynomial::definite_integral(double x0, double x1) const {
        polynomial a = antiderivative();
        return a.eval(x0) - a.eval(x1);
    }


    polynomial polynomial::derivative( ) const {
        polynomial a;                                   
        for(int i = 1; i < MAXIMUM_DEGREE -1; i++) {       
            a.coef[i-1] = (coef[i+1] * (i+1));                
        }
        a.update_current_degree();
        return a;
    }
    double polynomial::eval(double x) const {
        double sum = 0.0;
        for(int i = 0; i < MAXIMUM_DEGREE; i++) {
            sum += (coef[i] * pow(x, i));
        }
        return sum;
    }
    bool polynomial::is_zero( ) const {
       return (coef[current_degree] == coef[0]);     
    }
    unsigned int polynomial::next_term(unsigned int e) const {
        for(int i = e+1; e < MAXIMUM_DEGREE; i++) {       // Start at e+1 until
            if(coef[i] != 0)                        // If there is a nonzero coef exponent, return i
                    return i;                       // returns next term i
        }
        return 0;            
    }
    unsigned int polynomial::previous_term(unsigned int e) const {
        for(int i = e-1; i >= 0; i--) {             // Start at e-1 until 0
            if(coef[i] != 0)                        // If there is a nonzero coef exponent, return i
                return i;                           // returns previous term i
        }
        return UINT_MAX;      
    }



    // // NON-MEMBER BINARY OPERATORS
    polynomial operator +(const polynomial& p1, const polynomial& p2)
    {
        polynomial tmp;   
         // Temporary polynomial
        for(int i = 0; i < polynomial::MAXIMUM_DEGREE+1; i++)                   // Iterate through 0 to 
            tmp.add_to_coef(p1.coefficient(i)+p2.coefficient(i), i);    // Call coefficient() function on p1 and p2
        return tmp;
    }

    polynomial operator -(const polynomial& p1, const polynomial& p2) {
        polynomial tmp;
        for(int i = 0; i < polynomial::MAXIMUM_DEGREE+1; i++)
            tmp.add_to_coef(p1.coefficient(i)-p2.coefficient(i), i);    // Call coefficient() function on p1 and p2
        return tmp;
    }
    polynomial operator *(const polynomial& p1, const polynomial& p2) {
        assert( (p1.degree() + p2.degree()) <= polynomial::MAXIMUM_DEGREE);  // Highest degree of p1 and p2 smaller than 29
        polynomial tmp;                                                      // Temporary polynomial
        for(int i = 0; i <= p1.degree(); i++)
            for(int j = 0; j <= p2.degree(); j++)
                tmp.add_to_coef(p1.coefficient(i)*p2.coefficient(j), i+j); // Assign temp.data[i+j] = p1.data[i]*p2.data[i]
        return tmp;
    }
    
    // NON-MEMBER OUTPUT FUNCTIONS
    std::ostream& operator << (std::ostream& out, const polynomial& p)
    {
        unsigned int i = p.degree();
        streamsize s = out.precision();
        out << fixed;
        out << setprecision(1);
        for(int i = p.degree(); i >= 0; i--) {              // Start at highest exponent and move down calling previous_term()
            if(p.degree() == 0) 
                out << p.coefficient(0);
            else if(p.coefficient(i) != 0) {        
                if(i == p.degree())                             // At highest exponent
                    out << p.coefficient(i) << "x^" << i << ' ';   // Print as `(-/+)ax^i `
                else if(i < p.degree() && i > 1) {              // If not highest and not first coefficient
                    if(p.coefficient(i) < 0)
                        out << "- ";                            // If negative add `- `
                    else    
                        out << "+ ";                            // If positive add `+ `
                    out << fabs(p.coefficient(i)) << "x^" << i << ' ';   // print `ax^i `
                }
                else if(i == 1) {
                    if(p.coefficient(i) < 0)
                        out << "- ";                            // If negative add `- `
                    else
                        out << "+ ";                            // If positive add `+ `
                    out << fabs(p.coefficient(i)) << "x ";             // print `ax `
                }
                else if(i == 0) {
                    if(p.coefficient(i) < 0)
                        out << "- ";                            // If negative add `- `
                    else
                        out << "+ ";                            // If positive add `+ `
                    out << fabs(p.coefficient(i));                    // print `a`
                }
            }
        }
        out.unsetf(ios_base::floatfield);
        out << setprecision(s);
        return out;
    }
}