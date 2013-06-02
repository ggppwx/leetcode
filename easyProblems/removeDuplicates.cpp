// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this in place with constant memory.

// For example,
// Given input array A = [1,1,2],
// Your function should return length = 2, and A is now [1,2].


#include <iostream>

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int temp = -100000;
        for ( int i = 0; i < n ; ) {
            if ( temp == A[i]) {
                // remove current item 
                for (int j = i ; j < n - 1; j++) {
                    A[j] = A[j+1];
                }
                n-- ; 
            }else {
                temp = A[i];
                i++;  /* pitfall here, note the case [1,1,1] */
            }   
        }

        return n ; 
        
    }
};

