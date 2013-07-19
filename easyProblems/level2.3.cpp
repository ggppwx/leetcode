// add binary
class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool carry = false;
        string result; 
        for (int i = 0; i < a.size() || i < b.size(); ++i) {
            
            if (i >= a.size() ) {
                char bdigit = b[b.size() - 1 - i ];
                
                if (carry == true &&  bdigit == '1') {
                    result = "0" + result;
                    carry = true;
                }else if (carry == true && bdigit == '0') {
                    result = "1" + result;
                    carry = false;
                }else if (carry == false && bdigit == '1'){
                       result = "1" + result;
                        carry = false;
                }else if (carry == false && bdigit == '0') {
                    result = "0" + result;
                    carry = false; 
                }
                continue;
            }
            
            if (i >= b.size() ) {
                char adigit = a[a.size() - 1 - i ];
                if (carry == true &&  adigit == '1') {
                    result = "0" + result;
                    carry = true;
                }else if (carry == true && adigit == '0') {
                    result = "1" + result;
                    carry = false;
                }else if (carry == false && adigit == '1'){
                       result = "1" + result;
                        carry = false;
                }else if (carry == false && adigit == '0') {
                    result = "0" + result;
                    carry = false; 
                }
                continue;
                
            }
            
            
            char adigit = a[a.size() - 1 - i ];
            char bdigit = b[b.size() - 1 - i ];
            
        
            
            if ( adigit == '1' && bdigit == '1' ) {
                if ( carry == true ){
                    result = "1" + result;
                }else {
                    result = "0" + result;
                }
                
                carry = true;
            }else if (adigit == '1' || bdigit == '1' ) {
                if ( carry == true ) {
                    result = "0" + result;
                    carry = true;
                }else {
                    result = "1" + result;
                    carry = false;
                }
            
            }  else {
                if ( carry == true ) {
                    result = "1" + result;
                }else {
                    result = "0" + result;
                }
                carry = false;
            }
            
        }
        
        if (carry == true ){
            result = "1" + result;
        }
        
        return result;
        
        
        
    }
};



// remove duplates 
// duplicates are allowed at most twice
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int temp;
        int tempCount = 0;
        
        for (int i = 0; i < n ;) {
            int current = A[i];            
            if ( current != temp ) {
                temp = current; 
                tempCount = 0;
                ++i;
            }else if (tempCount < 1) { /* notice that this is before incrementing*/
                tempCount ++;
                ++i;
                
            }else {
                // remove current item
                int j = i;
                while(j < n-1){
                    A[j] = A[j+1];
                    j++; /* don't forget increment */
                }
                n--;
            }                        
        }
        return n;              
    }
};


// merge sorted array B to A
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lP = 0;
        int i = 0;
        for (; i < n && lP < m; ) {
            int right = B[i];            
            if ( A[lP] < right ) {
                lP ++ ;
                continue;
            }
                        
            if ( A[lP] >= right){
                // insert to A
                int tmp = m;
                while (tmp > lP) {  /* the correct way to insert a numberg to array */
                    A[tmp] = A[tmp -1];
                    tmp --;
                }
                A[lP] = right;
                m ++;
                lP ++ ;
                i ++ ;
                
                continue;
            } 
        }
        
        if (lP == m ){
            for (; i < n; ++i) {
                A[lP] = B[i];
                ++lP;
            }            
        }
    }
};



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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        return sortedArrayToBST(num, 0, num.size() -1);
        
    }
    
    /* this is really like merge sort 
       divide the problem to a sub problem 
       top- down approach: like pre-order traversal 
     */
TreeNode* sortedArrayToBST(vector<int>& arr, int start, int end) {
    if (start > end) return NULL;
    // same as (start+end)/2, avoids overflow.
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(arr[mid]);
        node->left = sortedArrayToBST(arr, start, mid-1);
        node->right = sortedArrayToBST(arr, mid+1, end);
        return node;
    }      
    
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    /*
      this is like in-order traversal 
     */
    
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode *h = head;
        int count = 0 ; 
        while ( h != NULL ) {
            h = h -> next;
            count++; 
        }
                
       return build( 0, count -1, head ) ;  
    }
    
    
    TreeNode *build (int start, int end, ListNode * &n ) 
    {
        if ( start > end )
            return NULL;
        
        
        int mid = start + (end - start )/2 ;
        TreeNode * left = build ( start, mid - 1, n ); 
        
        TreeNode *tmp = new TreeNode(n->val); // statt from first node 
        
        tmp -> left = left; 
        
        n = n -> next;
        TreeNode * right = build( mid+1, end, n );
        tmp -> right = right; 
        
        
        
    }
};
