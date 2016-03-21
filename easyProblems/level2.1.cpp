// Given a linked list, remove the nth node from the end of list and return its head.
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3-
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        /* 2 pointers is the key !!! */

        ListNode *current = head;
        ListNode *left = NULL;
        int count = 1;
        
        if (head == NULL)
            return NULL;
        
        while(current != NULL){
            if (count == n){
                left = head;
            }
            
            if (current -> next == NULL ){
                if ( left != NULL ) {
                    return left->next;
                }
            }

            if (current -> next -> next == NULL) {
                if (left != NULL ) {
                    ListNode *temp = left -> next;
                    left -> next = left -> next -> next;
                    delete temp; 
                    return head;
                }
            }
                        
            current = current -> next; 
            if (left != NULL) {
                left = left -> next;
            }
            count ++;
        }

    }
};


// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
class Solution {
    /* use stack */
public:
   bool isPair(char left, char right)
    {
        if (left == '(' && right == ')')
            return true;
            
        if (left == '{' && right == '}')
            return true;
            
        if (left == '[' && right == ']' )
            return true;            

        return false;
    }

    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> chars;
        for (size_t i = 0 ; i < s.size(); ++i ) {
            if (!chars.empty() && isPair(chars.top(),s[i])){
                chars.pop();
            }else{                
                chars.push(s[i]);
            }
        }
        
        if(chars.empty()){
            return true;
        }else {
            return false;
        }
    }
};


// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *newList = NULL;
        ListNode *start = NULL;
        ListNode *left = l1;
        ListNode *right = l2;
        while(left != NULL && right != NULL){
            if (left -> val < right -> val ) {
                // put left to new list
                if ( newList == NULL){
                    newList = left;
                    start = newList;
                }else{
                    newList -> next = left;
                    newList = newList -> next; /*!! the way to 
                                                 insert a node to a new link list, don't forget to move the pointer to link list*/
                }                
                left = left -> next;
                
            } else {
                if (newList == NULL){
                    newList = right;
                    start = newList;
                }else{
                    newList -> next = right; 
                    newList = newList -> next;
                }
                right = right -> next;
            }   
            
        }
        
        
        if ( left == NULL ){
            if (newList == NULL)
                return right;
                
            newList -> next = right;
        }
        
        if (right == NULL){
            if (newList == NULL)
                return left;
            
            newList -> next = left;
        }
        
        return start; /*!! remeber return head. */
              
    }
};


// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// For example, given n = 3, a solution set is:
// "((()))", "(()())", "(())()", "()(())", "()()()"
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        N = n;
        result.clear();
        addPar("", 0);
        return result;
    }
        
    void addPar(string current, int level){
        if ( level == N * 2 ) {
            if (isValid(current)){
                result.push_back(current);
            }
            return;
        }
        
        addPar(current + "(" , level + 1);        
        addPar(current + ")" , level + 1);
    }
    
    bool isValid(string s)
    {
        stack<char> st;
        for(size_t i = 0; i<s.size();++i){
            if (st.empty()){
                if ( s[i] == ')' ){
                    return false;
                }else{
                    st.push(s[i]);
                }
                continue; /*pitfall here !!! 
                            notice the if condition in the loop*/
            }
            
            if (st.top() == '(' && s[i] == ')'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        if (st.empty()){
            return true;
        }else{
            return false;
        }
        
    }
    
    int N;    
    vector<string> result;
};
