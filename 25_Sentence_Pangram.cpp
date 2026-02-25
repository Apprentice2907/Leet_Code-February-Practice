// A pangram is a sentence where every letter of the English alphabet appears at least once.
// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

// Example 1:

// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.
// Example 2:

// Input: sentence = "leetcode"
// Output: false





// My solution but not optimal

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> unq(sentence.begin(), sentence.end());
        if(unq.size()==26) return true;
        return false;
    }
};





// Leetcode optimal solution

class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.length() < 26) return false;

        std::vector<bool> seen(26, false);
        int uniqueCount = 0;

        for (char c : sentence) {
            int index = c - 'a';
            if (!seen[index]) {
                seen[index] = true;
                uniqueCount++;
            }
            if (uniqueCount == 26) return true;
        }

        return uniqueCount == 26;
    }
};