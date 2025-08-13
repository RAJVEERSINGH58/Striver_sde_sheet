#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int low, int high, int mid, int& count) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += j - (mid + 1);
        }

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high, int& count) {
        if (low >= high)
            return;
        int mid = (high + low) / 2;
        mergeSort(arr, low, mid, count);
        mergeSort(arr, mid + 1, high, count);
        merge(arr, low, high, mid, count);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        mergeSort(nums, 0, n - 1, count);
        return count;
    }
};

int main() {
    
    return 0;
}