// problem 1: remove duplicate from sorted array 
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

// p2 remove elements 
// Given an array and a value, remove all instances of that value in place and return the new length.
// The order of elements can be changed. It doesn't matter what you leave beyond the new length.


class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0 ; i < n ;) {
            if ( A[i] == elem ) {
                // remove the elme 
                for (int j = i ; j < n-1; ++j) {
                    A[j] = A[j+1];
                }
                
                n--;
            }else {
                ++i;
            }
            
        }

        return n; 
        
        
    }
};

// p3 length of last words 
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// For example, 
// Given s = "Hello World",
// return 5.
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int count = 0;
        int last = 0; 
        while(s[i] != '\0'){
            if (s[i] == ' '){
                if (count != 0 ) { /* only record the lengh greater than 0 */
                    last = count;
                }
                count = 0;
            } else {
                count ++;
            }
            ++i;
        }
        if (count  == 0 ) { /* !! note that we need to store the lengh of last word. */
            return last;
        }
        return count ;
    }
};

// p4: plus one 
// Given a number represented as an array of digits, plus one to the number.
/*not correct, what if the digits are too many ???? */
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long number = 0;
        for (size_t i = 0 ; i < digits.size(); ++i) {
            number = number*10 + digits[i];
        }
        
        number += 1;
        std::vector<int> result;
        call(number, result);

        return result;
    }


void call(long currentNumber, std::vector<int>& result){
    int left = currentNumber%10;
    if (currentNumber/10 !=0) {
        call(currentNumber/10, result);
    }
    result.push_back(left);
    
}


};

/*
this is error prone question, common mistake is:
1, try to convert the digits to number. 

another solution is to get a reversed vector of digits, then inverse it 
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        pOne(digits, digits.size() - 1, result);
        return result;
    }
    

    void pOne(vector<int>& digits, int i, vector<int>& result)
    {
        int temp = digits[i] + 1;
        if ( i = 0 ) {
            if (temp == 10) {
                result.push_back(1);
                result.push_back(0);                
            }else {
                result.push_back(temp)
            }
        } 

        pOne(digits, i - 1, result);
        
        if(temp == 10){
            pOne(digits, i-1, result);
            temp = 0;
            result.push_back(temp);
        }else{
            // copy 
            for(int j = 0; j<= i-1; ++j){
                result.push_back(digits[j]);
                result.push_back(temp);
            }
        }
        
    }



};
