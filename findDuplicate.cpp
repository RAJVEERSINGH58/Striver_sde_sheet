#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n){
            int correctIdx = nums[i];
            if(nums[i]==nums[correctIdx]) return nums[i];
            else if(i==correctIdx) i++;
            else{
                swap(nums[i] , nums[correctIdx]);
            }
        }
        return -1;
    }
};

int main() {
    
    return 0;
}