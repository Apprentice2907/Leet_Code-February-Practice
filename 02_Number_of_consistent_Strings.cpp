// You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

// Return the number of consistent strings in the array words.

 

// Example 1:

// Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
// Output: 2
// Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
// Example 2:

// Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
// Output: 7
// Explanation: All strings are consistent.
// Example 3:

// Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
// Output: 4
// Explanation: Strings "cc", "acd", "ac", and "d" are consistent.





// My approach but not optimal

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s(allowed.begin(), allowed.end());
        int count = 0;

        for (string word : words) {
            bool ok = true;
            for (char ch : word) {
                if (s.find(ch) == s.end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) count++;
        }
        return count;
    }
};











// Optimal solution

// class Solution {
// public:
//     int countConsistentStrings(string allowed, vector<string>& words) {
//         int count=0 ,flag=0;
              
//         for (int i=0;i< words.size(); i++)
//         {
//               for (int j=0;j< words[i].size(); j++)
//               {
//                  for (int k=0;k < allowed.size() ; k++ )
//                  {

//                     if (words[i][j]==allowed[k])
//                     {
//                         flag=1;
//                         break;
//                     }
//                     else flag =0;
                  
//                  }
//                  if (flag==0)
//                  {
//                     break;
//                  }
                   
//               }
//                   if(flag==1)
//                   {
//                     count++;
//                   }
//         }
//         return count ;
//         }
           
// };


class Solution {
public:
    int countConsistentStrings(string& allowed, vector<string>& words) {
        bitset<26> ASet=0;
        for(char c: allowed)
            ASet[c-'a']=1;
        int cnt=0;
        for(string& w: words){
            bool consistent=1;
            for(char c: w){
                if (ASet[c-'a']==0){
                    consistent=0;
                    break;
                }
            }
            cnt+=consistent;
        }
        return cnt;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();