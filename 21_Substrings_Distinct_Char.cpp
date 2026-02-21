// A string is good if there are no repeated characters.

// Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

// Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "xyzzaz"
// Output: 1
// Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
// The only good substring of length 3 is "xyz".
// Example 2:

// Input: s = "aababcabc"
// Output: 4
// Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
// The good substrings are "abc", "bca", "cab", and "abc".






// My approach but not optimal 

class Solution {
public:
    int countGoodSubstrings(string s) {
        int count=0;
        if(s.length()==1) return 0;
        for(int i=0;i<s.length()-2;i++){
            string sub=s.substr(i,3);
            set<char> good(begin(sub),end(sub));
            if(good.size()==3){
                count+=1;
            }
        }
        return count;
    }
};








// Optimal solution leetcode sliding window logic

class Solution {
public:
    int countGoodSubstrings(string s) {
        vector<int>freq(26,0);
        int left=0,distCha=0,ans=0;
        for(int right=0;right<s.length();right++)
        {
            if(freq[s[right]-'a']==0) distCha++;
            freq[s[right]-'a']++;

            if(right-left+1==3)
            {
                if(distCha==3) ans++;
                if((--freq[s[left]-'a'])==0) distCha--;
                left++;
            }
        }
        return ans;
    }
};