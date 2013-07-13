//Given an index k, return the kth row of the Pascal's triangle.
//For example, given k = 3,
//Return [1,3,3,1].
//Note:
//Could you optimize your algorithm to use only O(k) extra space?

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> tmp;
        for (int i = 0; i <= rowIndex; ++i ) {
            
            vector<int> A(i+1);
            for (int j = 0; j <= i ; ++j) {
                if ( j == 0 || j == i) {
                    A[j] = 1;
                }else { 
                    A[j] = tmp[j-1] + tmp[j];                     
                }
                
            }
            
            tmp = A; 
            
        }
        return tmp;
          
    }
};
