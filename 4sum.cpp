#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int first = nums[i];
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int second = nums[j];
                vector<int> v;
                int k = j + 1;
                int m = n - 1;
                while (k < m) {
                    int third = nums[k];
                    int fourth = nums[m];
                    long long sum = (long long)first + (long long)second + (long long)third + (long long)fourth;
                    if (sum == target) {
                        v = {first, second, third, fourth};
                        ans.push_back(v);
                        m--;
                        k++;
                        while (k < m && nums[m] == nums[m + 1])
                            m--;
                        while (k < m && nums[k] == nums[k - 1])
                            k++;
                    } else if (sum < target) {
                        k++;
                    } else
                        m--;
                }
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}