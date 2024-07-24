#include <iostream> 
#include <cassert>
#include <cmath>
#include "sequence1.h"

using namespace std;
using namespace coen79_lab3;

namespace coen79_lab3
{
    //post condition: sequence contructor initializes the sequence 
    sequence::sequence ()
    {
		current_index =0;
		used =0;
    }

    //post condition:  sets the current index of the sequence to the first space in the array
    void sequence::start()
    {
		current_index = 0;
    }

    //post condition: set sth ecurrent index of the sequence to the last element of the current sequence
    void sequence::end()
    {
		for (int i = (CAPACITY-1); i >= 0; i--){
	    	current_index = i;
	    	if(is_item() == true){
				break;
	    	}
		}
    }

    //post condition: sets the current index of the sequence to the end of the array
    void sequence::last() 
    {
		current_index = CAPACITY - 1;
    }

    //pre condition: ensure there is an item in the current position
    //post condition: moves the index of the sequence up one spot
    void sequence::advance()
    {
		assert(is_item());
		if (current_index != (CAPACITY-1)){
	    	current_index++;
		}
    }

    //pre condition: ensure teh current index is not zero
    //post condition: move sthe current index down one position
    void sequence::retreat()
    {
		if(current_index != 0){
	    	current_index--;
		}
    }

    void sequence::insert(const value_type& entry)
    {
		assert(size() < CAPACITY);

		if(used ==0){
		data[used] = entry;
		current_index =0;
		}else{
	    	for(int i = used; i > current_index; i--){
			data[i] = data[i-1];
	    	}
		data[current_index] = entry;
		}
		//data[current_index] = entry;
		used++;
    }

    //pre: ensure there is space in array 
    //post: attaches a value in the sequence following the current itrm
    void sequence::attach(const value_type& entry)
    {
		assert(size() < CAPACITY);

		if(used > 0){
	    	for(int i = used -1; i > current_index; --i){
			data[i+1] = data[i];
	    	}
	    	data[current_index+1] = entry;
	    	current_index++;
		} else {
	    	data[current_index] = entry;
		}
		used++;
    }

    // pre: ensure there is an item at the current index
    // post: remove the item at the current index and fills gap by shifting proceeding items back one position
    void sequence::remove_current()
    {
		assert(is_item() == true);

		for(int i = current_index+1; i < used; i++){
	    	data[i-1] = data[i];
		}
		used --;
		if(is_item() == false) {
	    	current_index = 0;
		}
    }

    //pre: ensure there is space in the array
    //post: attaches an item at the back of the sequence
    void sequence::insert_front(const value_type& entry)
    {
		assert(size() < CAPACITY);

		for(int i = used; i >=0; i--){
	    	data[i] = data[i-1];
		}

		data[0] = entry;
		used++;
		current_index = 0;
    }

    //pre: ensure there is space in 
    //post: attaches an item at the back of the sequence
    void sequence::attach_back(const value_type& entry)
    {
		assert(size() < CAPACITY);

		data[used] = entry;
		current_index = used;
		used++;
    }

    //pre: ensure that there's an item in the first element in the array
    //post: removes the first element in the array and shifts all proceeding items back one position
    void sequence::remove_front() {
		current_index = 0;
		assert(is_item() == true);

		for(int i = 0; i < used; i++){
			data[i-1] = data[i];
		}
		used --;
	}

	//post: return lhs as a sequence that contains all values of lhs, proceeded by all values of the sequence rhs
	sequence operator +=(sequence& lhs, sequence& rhs)
	{
		rhs.start();
		for(int i = 0; i < rhs.size() - 1; i++) {
			lhs.attach(rhs.current());
			rhs.advance();
		}
		return lhs;
	}

	sequence::size_type sequence::size() const{
		return used;
	}

	//post: returns tru if there is an item at the current index
	bool sequence::is_item() const 
	{
		return (current_index < used);
	}

	//pre: ensures there is an item at the current position
	//post: returns the vale of the item at the current position
	sequence::value_type sequence::current()const{
		assert(is_item() == true);
		return data[current_index];
	}

	//pre: ensures there is an item at the current position
	// post: returns the value of the item at the current position
	sequence::value_type sequence::operator[](int index) const
	{
		assert(index < used);
		return data[index];
	}

	// post: returns the mean of the values
	double sequence::mean() const
	{
		double sum;
		
		for (int i =0; i < used; i++)
		{
				sum += data[i];
		}
		return sum/used;
	}

	//post: returns the standard deviation of all values in the sequence
	double sequence::standardDeviation()const{
		double sum = 0;
		for(int i =0; i < used; i++){
			sum += data[i];
		}
		double mean = (double)sum/(double)used;

		double sqDiff = 0;
		for(int j = 0; j < used; j++){
			sqDiff += (data[j] - mean) * (data[j] - mean);
		}

		return sqrt(sqDiff/used);
	}

	//post: adds the value of the rhs sequence to the end of the sequence on the left, and returns it as a new sequence
	sequence operator +(const sequence& lhs, const sequence &rhs){
		sequence left(lhs);
		sequence right(rhs);
		right.start();
		for (int i = 0; i< right.size(); i++){
			left.attach(right.current());
			right.advance();
		}
		return left;
	}
	sequence::value_type summation(const sequence &s){
		sequence t(s);
		t.start();
		int sum = 0;
		for(int i = 0; i < t.size(); i++) {
			sum += t.current();
			t.advance();
		}
		return sum;
	}
}
