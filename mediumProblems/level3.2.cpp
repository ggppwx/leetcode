// 3 sum
// key: 1, sorting  2, use std::set data structure to get unique vector  

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        
        //sort the vector
        set<vector<int> > res;
        sort(num.begin(), num.end());
    
        
        for (int a = 0; a < num.size(); ++a ){
            int b = a + 1; 
            int c = num.size() - 1;
            int num1 = num[a];
            while(b < c ){
                
                int num2 = num[b];
                int num3 = num[c];
                if (num1 + num2 + num3 == 0){
                    vector<int> temp;
                    temp.push_back(num1);
                    temp.push_back(num2);
                    temp.push_back(num3);
                    res.insert(temp);
                    b++;
                    c--;
                }else if (num1 + num2 + num3 < 0){
                    b ++;
                }else{
                    c --;
                }
                
                
            }
            
            
        }
        
        vector<vector<int> > result(res.begin(), res.end());
        return result;
        
        
    }
};



// merge k sorted list 
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *newList = NULL;
        ListNode *curr = NULL; 
        int ind; 
        while (ind != -1 ) {
            ind = findMinNode(lists);
            if (ind == -1 ) {
                break;
            }
            ListNode *newNode = lists[ind];
            lists[ind] = lists[ind] -> next ; 
            newNode -> next = NULL;
            
            if ( curr == NULL ) {
                curr = newNode;
                newList = curr; 
            }else {
                curr -> next = newNode;
                curr = curr -> next; 
            }
            
        }
        return newList;
        
    }
    
    int findMinNode(vector<ListNode *> lists){
        int min = 1000000;
        int res = -1;
        for (int i = 0; i < lists.size() ; ++i) {
            ListNode *node = lists[i];
            if ( node == NULL ) {
                continue; 
            }
            
            if ( node -> val < min ){
                min = node ->val; 
                res = i;
            }
        }
        return res;
    }
    
};
