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
