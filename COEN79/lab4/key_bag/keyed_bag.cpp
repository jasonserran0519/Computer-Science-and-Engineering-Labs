// FILE: keyed_bag.cpp
// CLASS IMPLEMENTED: keyed_bag (see keyed_bag.h for documentation)
//
//
//
//
// INVARIANT for the keyed_bag class:
// 1. The number of items in the keyed_bag is in the member variable used;
// 2. For an empty keyed_bag, we do not care what is stored in any of data; for a
// non-empty keyed_bag the items in the keyed_bag are stored in data[0] through
// data[used-1], and we don't care what's in the rest of data.
#include <algorithm> // Provides copy function
#include <cassert> // Provides assert function
#include "keyed_bag.h"

using namespace std;

/// @brief 
namespace coen79_lab4
    {
    const keyed_bag::size_type keyed_bag::CAPACITY;
    
    bool keyed_bag::erase(const key_type& key)
    {                          
        for(int i = 0; i < used; i++) {             
            if(keys[i] == key) {                    
                for(int j = i; j < used-1 ; j++) {  
                    keys[j] = keys[j+1];            
                    data[j] = data[j+1];            
                }
                used--;
                return true;                        
            }
        }
        return false;         
    }       
    void keyed_bag::insert(const value_type& entry, const key_type& key)
    {    
        assert(size() < CAPACITY);
        if (has_key(key) == true)
            return;     
        keys[used] = key;                           
        data[used] = entry;                          
        used++;
    }
    void keyed_bag::operator +=(const keyed_bag& addend)
    // Library facilities used: algorithm, cassert
    {
        assert(size() + addend.size() <= CAPACITY);                 
        for(int i = 0; i < addend.used; i++) {      
            if( !has_key(addend.keys[i]) ) {        
                keys[used] = addend.keys[i];        
                data[used] = addend.data[i];       
                used++;
            }
        }
    }
    bool keyed_bag::has_key(const key_type& key) const {
        for(int i = 0; i < used; i++) {             
            if(keys[i] == key) {                    
                return true;                        
            }
        }
        return false;     
    }
    keyed_bag::value_type keyed_bag::get(const keyed_bag::key_type& key) const {
        for(int i = 0; i < used; i++) {             
            if(keys[i] == key) {                    
                return data[i];                        
            }
        }          
    }
    keyed_bag::size_type keyed_bag::count(const value_type& target) const
    {
        size_type count = 0;                        // Temporary counter
        for(int i = 0; i < used; i++) {             // Iterate from 0 to used
            if(data[i] == target) {                 // If we find target in data[]
                count++;                            // increment count
            }
        }
        return count;
    }
    keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2)
    {
        assert((b1.size()+b2.size()) <= keyed_bag::CAPACITY);       // Check if b1 + b2 sizes is smaller than CAP
        keyed_bag temp;                             // Make temporary bag
        temp += b1;                                 // Call += operator overloaded function on b1
        temp += b2;                                 // Call += operator overloaded function on b2
        return temp;         
    }
        // Check whether the other keyed_bag shares a key with this keyed_bag.
    bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const {
        for(int i = 0; i < otherBag.used; ++i) {    // Iterate from 0 to otherBag.used
            if( has_key(otherBag.keys[i]) ) {       // call has_key on otherBag's key[] per i
                return true;                        // return true on first time we find match
            }
        }
        return false;
    }
}