// p1
// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {        
        ListNode *currNode = head;
        ListNode *previousNode = NULL;
        int currVal = -10000;
        while(currNode){
            if (currNode -> val == currVal ) {
                // remove current 
                previousNode -> next = currNode -> next;
                delete currNode;
                currNode = previousNode -> next;

            }else {
                currVal = currNode -> val;
                
                // move to next node 
                previousNode = currNode;
                currNode = currNode -> next;
            }
        }
        return head;
    }
};


// Given two binary trees, write a function to check if they are equal or not.

// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {        
        // traverse tree 
        return compare(p, q);
        
    }

    bool compare(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL) 
            return true;

        if ((p == NULL && q != NULL) || (p!=NULL && q == NULL) ) {
            return false;
        }
        
        if ( p -> val != q ->val ){
            return false;
        }

        return compare(p -> left, q -> left) && 
            compare(p -> right, q -> right);
    }
};

// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL ){ /* conner case NULL in pointer based structure, i.e
                            tree,  link list
                            */
            return true;
        }

        return isEqual(root -> left, root -> right);        
        
    }

    bool isEqual(TreeNode* left, TreeNode *right)
    {
        if (left == NULL && right == NULL) 
            return true;


        if (left == NULL && right != NULL) {
            return false;
        }

        if (left != NULL && right == NULL) {
            return false;
        }

        if (left -> val != right -> val)
            return false;
        
        return isEqual(left -> left,  right -> right ) && 
            isEqual(left -> right, right -> left );
     

    }
    

};



// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node

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
    int maxDepth(TreeNode *root) {
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
