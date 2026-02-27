// A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
// Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: The square triples are (3,4,5) and (4,3,5).
// Example 2:

// Input: n = 10
// Output: 4
// Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).








// Brute force method 

class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for (int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if((i*i)+(j*j)==(k*k)) count=count+1;
                }
            }
        }
        return count;
    }
};







// Leetcode optimal solution

class Solution {
public:
    int countTriples(int n) {
        if(n < 5) return 0;
        int res = 0;
        for(int u = 2; u < sqrt(n) ; u++){
            for(int v = 1; v < u; v++){
                if(~(u - v) & 1 || gcd(u,v) != 1) continue;
                int c = u * u + v * v;
                if(c > n) continue;
                res += 2 * (n/c);
            }
        }
        return res;
        
    }
};