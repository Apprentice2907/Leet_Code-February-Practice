// A pangram is a sentence where every letter of the English alphabet appears at least once.

// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

// Example 1:

// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.
// Example 2:

// Input: sentence = "leetcode"
// Output: false







// Different approach

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s(sentence.begin(), sentence.end());
        return s.size() == 26;
    }
};






// my logic but not working properly

class Solution {
public:
    bool checkIfPangram(string sentence) {
        string s="abcdefghijklmnopqrstuvwxyz";
        size_t pos = sentence.find(s);
        return pos;
    }
};





// ChatGPT improved coded

class Solution {
public:
    bool checkIfPangram(string sentence) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (sentence.find(c) == string::npos)
                return false;
        }
        return true;
    }
};
