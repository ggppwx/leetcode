#include <vector>
#include <iostream>

using namespace std;
// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    bool isBalanced(TreeNode *root) {
        /*
          NOTE: need to consider all situations in tree 
         */
        if (root == NULL){
            return true;
        }

        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);

        if (abs(left-right) > 1 ) 
            return false; 

        return isBalanced(root->left) && isBalanced(root -> right);
    }

    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL )
            return 0;

        int leftDepth = maxDepth(root -> left);
        int rightDepth = maxDepth(root -> right);

        if (leftDepth > rightDepth)
            return (leftDepth + 1);
        else 
            return (rightDepth + 1);

    }

};


// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return 0; 
    
        if (root -> left == NULL && root -> right == NULL) // leaf
            return 1;
            
        /* this is only one special case.
        if (root -> left == NULL || root -> right == NULL) 
            return 2;
        */
        /*consider this one-side binary tree 
         */
        if ( root -> left == NULL )
            return minDepth(root -> right) +1;

        if ( root -> right == NULL )
            return minDepth(root -> left) + 1;

        int left = minDepth(root -> left);
        int right = minDepth(root ->right);

        if (left < right)
            return left + 1;
        else 
            return right + 1;
        
    }
};



// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution3 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if ( root == NULL ) /* check the case that tree is empty */
            return false;

        if ( root -> left == NULL && root -> right == NULL){
            // check the leaf node 
            if ( root == NULL ){
                return false;
            }

            if ( sum == root -> val ){
                return true;
            }else{
                return false;
            }
        }

        return (hasPathSum(root -> left, sum - root->val)
                || hasPathSum(root -> right, sum - root ->val));
        

    }
};


// Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
class Solution4 {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        d_shortest = findShortest(start, end, dict);

        d_result.clear();
        vector<string> temp;
        if (dict.find(start) != dict.end()){
            temp.push_back(start);
            dict.erase(start);
            find1(start, end, dict, temp);
            dict.insert(start);
        }

        
        
        
        return d_result;  
    }
    

    int findShortest(string start, string end, unordered_set<string> &dict)
    {

        int len = start.size();

        queue<string> q;
        queue<int> qPath;
        set<string> hash;
        
        qPath.push(0);    
        q.push(start);

        while(!q.empty()){
            string s = q.front();
            int level = qPath.front();

            if (s == end) {
                return level;
            }

            qPath.pop();
            q.pop();
            dict.erase(s);
            
            for (int i = 0 ; i < s.size(); ++i) {
                for(int j = 0; j < 26; ++j){
                    string newS = s;
                    if(newS[i] != 'a' +j){
                        newS[i] = 'a' + j;
                    }
                    if (dict.find(newS) != dict.end()){
                        /// record 
                        if ( hash.find(newS) == hash.end()){
                            hash.insert(newS);
                            qPath.push(level+1);
                            q.push(newS);
                        }
                    }                    
                }
            }

        }
        return dict.size();         
    }

    
    void find1(string start, string end, unordered_set<string> &dict, vector<string>& temp)
    {
        /*TIME limit exceed !!!  !!!!!*/

        if (start == end){
            if (d_result.empty()){
                d_result.push_back(temp);    
            }else{
            
                if (d_result.back().size() > temp.size()){
                    d_result.clear();
                    d_result.push_back(temp);
                }else if (d_result.back().size() == temp.size()){
                    d_result.push_back(temp);
                }     
            }
            return;
        }       
        
        if (dict.empty()){
                
            return;
        }

        if (temp.size() > d_shortest+1)
            return;

        if (!d_result.empty() && d_result.back().size() <= temp.size()) {
            return;
        }
        
        for (int i = 0 ; i < start.size(); ++i) {
            for(int j = 0; j < 26; ++j){
                string newstart = start;
                newstart[i] = 'a' + j;
                if ( dict.find(newstart) != dict.end()){
                    // 
                    temp.push_back(newstart);
                    dict.erase(newstart);
                    find1(newstart, end, dict, temp);
                    temp.pop_back();
                    dict.insert(newstart);
                }
                
            }
        }  
        
    }

    vector<vector<string>> d_result;    

    int d_shortest;
    
};



int main(int argc, char* argv[])
{

    return 0;
}
