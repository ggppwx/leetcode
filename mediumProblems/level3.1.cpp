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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *newList = NULL;
        ListNode *head = NULL;
        
        ListNode* left = l1;
        ListNode* right = l2;
        
        int carryBit = 0; 
        while(left || right){
            int leftVal = 0;
            if (left){
                leftVal = left -> val;
            }
            
            int rightVal = 0;
            if (right){
                rightVal = right -> val; 
            }
            
            int sum = leftVal + rightVal + carryBit; 
            
            
            if (sum >= 10) {
                sum = sum - 10;
                carryBit = 1; 
            } else {
                carryBit = 0;  /* !! don't forget reset carry bit !!!!*/
            }
            
            
            ListNode *newNode = new ListNode(sum);
            newNode -> next = NULL;
            if (newList == NULL ){
                newList = newNode; 
                head = newList; 
            }else{
                newList -> next = newNode;
                newList = newList -> next;
            }
            
            if(left)   /* !!! dont forget check if a node is valid */
                left = left -> next;
            
            if(right)
                right = right -> next; 
        }
        
        if ( carryBit == 1 ) { /* !!! don't forget the last node */
            ListNode *newNode = new ListNode(1);
            newList -> next = newNode;
        }
        
        return head;
        
    }
};
