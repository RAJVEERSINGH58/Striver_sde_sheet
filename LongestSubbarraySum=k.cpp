#include<bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0;
    long long sum = a[0]; // assign sum = 0th index
    int maxLen = 0;
    int n = a.size();
    
    while(right < n) {
        while(left <= right && sum > k) { // until sum is not smaller than k move left pointer
            sum -= a[left];
            left++;
        }
        
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        
        right++; // move right pointer
        if(right < n) sum += a[right]; // add right pointer to the sum
    }
    
    return maxLen;
}
