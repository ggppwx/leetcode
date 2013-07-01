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
