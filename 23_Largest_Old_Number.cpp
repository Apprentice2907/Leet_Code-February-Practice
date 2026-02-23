// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: num = "52"
// Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
// Example 2:

// Input: num = "4206"
// Output: ""
// Explanation: There are no odd numbers in "4206".
// Example 3:

// Input: num = "35427"
// Output: "35427"
// Explanation: "35427" is already an odd number.








// My approach but not working 

class Solution {
public:
    string largestOddNumber(string num) {
        int max=0;
        int x;
        for (int i = 0; i < num.size(); i++) {
            for (int len = 1; len <= num.size() - i; len++) {
                string sub= num.substr(i, len);
                x = stoi(sub);
                if(x%2!=0){
                    if(x>max) max=x;
                }
            }
        }
        return to_string(x);
    }
};








// Optimized solution and optimal too

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            int digit = num[i] - '0';
            if (digit % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};