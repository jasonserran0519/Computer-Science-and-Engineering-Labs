#include <iostream>

using namespace std;

class Complex
{
    Complex (){
	int a= 1;
	int b = 2;
	int c = 5;
    }
    public:
	Complex mulAdd(){
	    Complex ans = a * b + c;
	   return ans;
	}
    
}


int main()
{
    Complex g, i ,h;
    Complex z = mulAdd(g,h,i);
    
}

