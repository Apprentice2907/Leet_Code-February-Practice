// A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

// Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

// Example 1:

// Input: s = "YazaAay"
// Output: "aAa"
// Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
// "aAa" is the longest nice substring.
// Example 2:

// Input: s = "Bb"
// Output: "Bb"
// Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
// Example 3:

// Input: s = "c"
// Output: ""
// Explanation: There are no nice substrings.






// My approach

class Solution {
public:
    bool isNice(const vector<int>& lower, const vector<int>& upper) {
        for (int i = 0; i < 26; i++) {
            if ((lower[i] > 0 && upper[i] == 0) ||
                (upper[i] > 0 && lower[i] == 0)) {
                return false;
            }
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        string best = "";
        int n = s.length();

        for (int i = 0; i < n; i++) {
            vector<int> lower(26, 0), upper(26, 0);

            for (int j = i; j < n; j++) {
                char c = s[j];

                if (islower(c))
                    lower[c - 'a']++;
                else
                    upper[c - 'A']++;

                if (isNice(lower, upper)) {
                    int len = j - i + 1;
                    if (len > best.length()) {
                        best = s.substr(i, len);
                    }
                }
            }
        }
        return best;
    }
};











// Leetcode optimal solution

class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.length() < 2) return "";
        unordered_set <char> st(s.begin() , s.end());
        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            if(st.count(toupper(s[i])) == 0 || st.count(tolower(s[i])) == 0){
                string left = longestNiceSubstring(s.substr(0 , i));
                string right = longestNiceSubstring(s.substr(i+1));
            
                return left.size() >= right.size() ? left : right;
            }
        }
        return s;
    }
};