// You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

// The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

// Return the minimum number of operations needed to make s alternating.

// Example 1:

// Input: s = "0100"
// Output: 1
// Explanation: If you change the last character to '1', s will be "0101", which is alternating.
// Example 2:

// Input: s = "10"
// Output: 0
// Explanation: s is already alternating.
// Example 3:

// Input: s = "1111"
// Output: 2
// Explanation: You need two operations to reach "0101" or "1010".







// My logic but not correct as it fails some testcases

class Solution {
public:
    int minOperations(string s) {
        int count=0;
        if(s.length()==1) return 0;
        if(s.length()==2){
            if(s[0]!=s[1]) return 0;
            else return 1;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]!=s[i+2]) count=count +1;
        }
        return count;
    }
};







// ChatGPT optimized my code and optimal too 

class Solution {
public:
    int minOperations(string s) {
        int count1 = 0, count2 = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != (i % 2 == 0 ? '0' : '1')) count1++;
            if (s[i] != (i % 2 == 0 ? '1' : '0')) count2++;
        }

        return min(count1, count2);
    }
};
