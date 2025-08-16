#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (int x : s) {
            if (s.find(x - 1) == s.end()) {
                int current = x;
                int streak = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    streak++;
                }

                ans = max(ans, streak);
            }
        }

        return ans;
    }
};


int main() {
    
    return 0;
}