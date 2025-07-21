#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//leethub
    bool isPalindrome(int x) {
        if (x < 0) return false; 
        
        long long revNum = 0; 
        long long dup = x;    
        while (x > 0) {
            int ld = x % 10;
            revNum = (revNum * 10) + ld;
            x = x / 10;
        }

        return revNum == dup;
    }
};

// TC: O(log 10)
// SC: O(1)