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
class Solution {
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
class Solution {
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

