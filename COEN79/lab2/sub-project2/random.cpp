#include <cassert>
#include <iostream>
#include "random.h"

using namespace std;

namespace coen79_lab2
{

	rand_gen::rand_gen(int seed, int multiplier, int increment, int modulus)
	{
	    this -> seed = seed;
	    this -> multiplier = multiplier;
	    this -> modulus = modulus;
	    this -> increment = increment;
	
	}
	void rand_gen::set_seed(int new_seed)
       	{
	    seed = new_seed;
	}

	int rand_gen::next()
       	{
	    int gen;
	    gen = ((multiplier * seed * increment ) % modulus);
	    seed = gen;
	    return gen;
	}
	
	void rand_gen::print_info() 
	{
	    cout << "Seed; " << seed << endl;
	    cout << "Multiplier: " << multiplier << endl;
	    cout << "Increment: " << increment << endl;
	    cout << "Modulus: " << modulus << endl;
	}
}
