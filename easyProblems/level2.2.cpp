// Given a linked list, swap every two adjacent nodes and return its head.
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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL )
            return NULL;
        
        ListNode* left = head;
        ListNode* right = left -> next;
        
        if(right == NULL)
            return left;
        
        ListNode* newHead = right;
        while(right && right->next){
            
            ListNode* left1 = left;
            ListNode* right1 = right;
            
            
            left = left->next -> next;
            right = right -> next -> next;
            
            if (right == NULL ) {
                left1 -> next = left;
            }else{
                left1 -> next = right;
            }
            
            right1 -> next = left1;
            
            
        }
        
        if (right == NULL) /*don't forget to check */
            return newHead;
        
        if (right -> next == NULL ){
            right -> next = left;
            left -> next = NULL;
        }
        
        return newHead;
        
    }
};


// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0;  i < n ; ++i) {
            if ( A[i] < target ) {
                
                continue;
            }else if ( A[i] > target ) {
                return i; 
            }else {
                return i;
            }
            
        }
        return n;
        
        
        
    }
};


// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
class Solution {
    /*
      Simple problem, only check if sudoku is valid.
      no need to check if sodoku is solvable !!
*/
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool allFlag = true;
        for (size_t i = 0; i < board.size() ; ++i) {
            for (size_t j = 0; j < board[i].size(); ++j) {
                char cell = board[i][j];
                if (cell == '.') {
                    
                    /*
                    allFlag = false;                    
                    // give a try
                    bool isSolvable = false;
                    
                    for (char digit = '1' ; digit <= '9'; digit = digit + 1 ) { 
                        if ( checkValid(i, j, digit, board) ) {
                            // digit is valid 
                            isSolvable = true;
                            board[i][j] = digit;
                                
                            if ( ! isValidSudoku(board) ){
                                board[i][j] = '.';   
                            }else {
                                return true;
                            }
                            
                            
                            
                            
                        }
                        
                    }                    
                    if ( ! isSolvable ) {
                        return false;
                    }
                    
                    */
                }  else {
                    
                    if ( !checkValid(i,j,cell,board))
                        return false;
                    
                    
                }
            }
        }
        
        return true;
        /*
        if (allFlag) {
            return true;            
        }
        */
        
        
    }    
    
    bool checkValid(int i, int j, char digit, const vector<vector<char> >& board)
    {
        // check vertical 
        
        for (int k = 0; k < board.size(); ++k) {
            if ( k == j )
                continue;
            if ( board[i][k] == digit ) {
                return false;
            } 
        } 
        
        for (int k = 0; k < board.size(); ++k) {
            if (k == i)
                continue;
            if ( board[k][j] == digit ) {
                return false;
            } 
        }         
        
        
        for ( int k1 = (i/3) * 3 ; k1 < (i/3) * 3 + 3; k1++) {
            for ( int k2 = (j/3)*3; k2 < (j/3) * 3 + 3; k2 ++) {
                if (k1 == i && k2 == j)
                    continue;
                    
                if (board[k1][k2] == digit) {
                    return false;
                }
            }
        }
        
        return true;    
    }
    
};


//You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

/*
stupid fab array !
... review dfs non-recursive solution. 

*/
class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> s(n+1);
        s[1] = 1;
        s[2] = 2;
        for (int i = 3; i <= n ; ++i) {
            s[i] = s[i-1] + s[i-2];
        }
        return s[n];
        
    }
};

// count and say
class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string current = "1";
        for (int i = 1 ; i <n; i++) {
            current = process(current);
        }
        return current;
        
    }  
    string process(string current)
    {
        int count = 0;
        char tmp = current[0];
        stringstream result; 
        for (int i = 0; i < current.size();++i){
            char digit = current[i];
            if ( tmp == digit ){
                count ++;
            } else {
                result << count << tmp ;
                tmp = digit;
                count = 1;
            } 
            
        }
        result << count << tmp; /* don't forget last digit !!*/
        return result.str();
    }
    
};
