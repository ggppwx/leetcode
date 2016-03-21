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


// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        dfs(root, 0);
        int sum = 0;
        for (int i = 0; i < result.size(); ++i){
            sum += result[i];
        } 
        return sum;
    }
    
    
    void dfs (TreeNode *node, int sum ) 
    {
        if(node == NULL ){
            return; 
        }
        
        int val = node -> val; 
        if (node -> left == NULL && node -> right == NULL ){
            // leaf 
            result.push_back( val + sum * 10 );
        } 
        
        dfs(node -> left, sum * 10 + val );
        
        dfs(node -> right, sum * 10 + val ); 
        
    }
      
    vector<int> result;
};


// two sum 
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        for (int i = 0; i< numbers.size() ; ++i) {
            for (int j = i + 1; j < numbers.size(); ++j) {
                if (numbers[i] + numbers[j] == target ) {
                    result.push_back(i + 1);
                    result.push_back(j+1);
                    return result;
                }   
            }
        }
        return result;
        
    }
};
