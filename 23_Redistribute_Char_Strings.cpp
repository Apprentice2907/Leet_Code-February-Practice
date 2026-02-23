// You are given an array of strings words (0-indexed).

// In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].

// Return true if you can make every string in words equal using any number of operations, and false otherwise.

// Example 1:

// Input: words = ["abc","aabc","bc"]
// Output: true
// Explanation: Move the first 'a' in words[1] to the front of words[2],
// to make words[1] = "abc" and words[2] = "abc".
// All the strings are now equal to "abc", so return true.
// Example 2:

// Input: words = ["ab","a"]
// Output: false
// Explanation: It is impossible to make all the strings equal using the operation.








// My approach but not optimal 

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> freq(26, 0);

        for (auto s : words) {
            for (char c : s) {
                freq[c - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] % n != 0) {
                return false;
            }
        }

        return true;
    }
};







// Leetcode optimal solution

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.empty()) return true;

        unordered_map<char, int> mpp;

        for(string &s : words){
            for(char ch : s){
                mpp[ch]++;
            }
        }

        int n = words.size();

        for(auto &m : mpp){
            if(m.second % n != 0){
                return false;
            }
        }

        return true;
    }
};