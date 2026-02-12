// Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

 

// Example 1:

// Input: s = "1001"
// Output: false
// Explanation: The ones do not form a contiguous segment.
// Example 2:

// Input: s = "110"
// Output: true
 






// Logical approach 

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zeroFound = false;

        for (char c : s) {
            if (c == '0') {
                zeroFound = true;
            }
            else if (zeroFound) {
                return false; 
            }
        }

        return true;
    }
};










// Mwy approach but didnt work in most of the cases

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag=false;
        for(int i=0;i<s.length();i++){
            if(s.length()==1 && s[0]=='1') {
                flag=true;
                break;
            }
            if(s[i]=='1'){
                if(s[i]==s[i+1]) {
                    flag= true;
                    break;
                }
                else{
                    flag= false;
                }
            }
        }
        return flag;
    }
};