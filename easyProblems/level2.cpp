// Reverse digits of an integer.
// Example1: x = 123, return 321
// Example2: x = -123, return -321
class Solution {
public:
    int reverse(int x) {
        int sign  = 1;
        if ( x <  0 ) {
            sign = -1;
        }
        x = abs(x);
        int sum = 0;        
        while( x > 0 ){            
            int d = x/10;
            int m = x%10;            
            sum = sum * 10 + m;
            x = x/10;            
        }                
        return sum*sign;        
    }
};


// Implement atoi to convert a string to an integer.
// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
class Solution {
public:
    int atoi(const char *str) {
        /* the problem is not clear enough */

        int i = 0;
        long sum = 0;
        bool startCount = false;
        int sign = 1;
        
        while(str[i] != '\0'){

            if (startCount != true && (str[i] == '+' || str[i] == '-')){
                startCount = true;
                if (str[i] == '-'){
                    sign = -1;
                }
                ++i;
                continue;
            } 
            
            if (startCount != true && (str[i] - '0' < 0 || str[i] -'0' > 9) && str[i] != ' ' )
                return 0;
            
            if ((str[i] - '0' >=0 && str[i] -'0' < 10) ) {
                if (!startCount){
                    startCount = true;
                    
                }
                
                /* !!!! how to check overflow ... */
                if((2147483647 - (str[i] - '0'))/10  < sum && sign == 1)
                    return 2147483647;
                
                if ((2147483648 - (str[i] - '0'))/10 < sum && sign == -1)
                    return -2147483648;
                
                sum = sum * 10 + (str[i] - '0');

                
            }else {
                if(startCount)
                    break;
                
                    
            }
            ++i;
        }
  
            
        return sum * sign;
                
    }
};

// Determine whether an integer is a palindrome. Do this without extra space.
/*
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
*/

class Solution {
public:
    int MAX_INT = 2147483647;
    
    bool isPalindrome(int x) {
        int temp = x;
        // reverse the integer 
        if ( reverseInt(x) && temp == x){
            return true;
        }
        return false;
    }

    bool reverseInt(int& x)
    {
        if ( x > MAX_INT ) 
            return false;
        int sum = 0;
        while(x > 0){
            int mod = x%10;
            
            if ( (MAX_INT - mod)/10 < sum ) {
                return false;
            }
            
            sum = sum * 10 + mod;                        
            x = x/10;
        }
        
        x = sum;
        return true;
            
    }
};

// Write a function to find the longest common prefix string amongst an array of strings.
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
               if (strs.empty())
            return "";
            
        int k = 0;
        string result;
        while(1) {
            char temp = ' ';
            for (int i = 0 ; i < strs.size(); ++i) {
                if ( k < strs[i].size()){
                    char current = strs[i][k];
                    if ( temp == ' ' ){ // first string
                        temp = current;
                        continue;
                    }
                    
                    if ( temp - current != 0 ) {
                        return result;     
                    } 
                    
                    
                }else {
                    return result;
                }
            }
            if (temp - ' ' == 0)
                return "";
                
            result += temp; /* don't use result[k] !!!! */
            ++k ;
        
        }
        
        
    }
};


// path sum 2 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        vector<int> path;
        sum1(root, sum, path);
        return result;
    }
    
    void sum1(TreeNode *root, int sum, vector<int>& path)
    {
        if (root == NULL ){
            return;
        }
        
        int current = root -> val;
        path.push_back(current);
        
        if ( root -> left == NULL && root -> right == NULL ){ // leaf node 
            if ( sum == root -> val ) {
                //  put the vector to result                                 
                result.push_back(path);
                path.pop_back();
                return; 
            }else {
                path.pop_back();
                return; 
            } 
        
        } 
 
        
        sum1(root->left , sum - current, path) ;
        
        sum1(root->right, sum - current, path );
        
        path.pop_back();
        
    }
    
    vector<vector<int> > result;
    
};

// pascial triangle 
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > A; 
        
        for (int i = 0; i < numRows; ++i) {
            
            // for each row , it has i + 1 items
            vector<int> temp(i+1);
            A.push_back(temp); 
            
            for (int j = 0; j <= i; ++j) {
                if ( j == 0 || j == i ){
                    A[i][j] = 1;
                } else {
                    A[i][j] = A[i-1][j-1] + A[i-1][j];
                }
                
                
            } 
            
        }
        
        return A;
        
    }
};

