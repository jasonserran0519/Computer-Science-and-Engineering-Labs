#ifndef STATS_H // Prevent duplicate definition
#define STATS_H
#include <iostream>
namespace coen79_lab2
{
    class statistician
    {
		public:
	    	statistician( );
	    	void next(double r);
	    	void reset( );
	    	
		int length( ) const;
	    	double sum( ) const;
	    	double mean( ) const;
	    	double minimum( ) const;
	    	double maximum( ) const;
	    
	    	friend statistician operator + (const statistician& s1, const statistician& s2);
		friend statistician operator * (double scale, const statistician& s);
	    
		private:
	    	double total; //The sum of all the numbers in the sequence
	    	int size; //How many numbers in the sequence
	    	double min; //The smallest number in the sequence
	    	double max; //The largest number in the sequence
    };

		bool operator ==(const statistician& s1, const statistician& s2);
}
	    #endif
