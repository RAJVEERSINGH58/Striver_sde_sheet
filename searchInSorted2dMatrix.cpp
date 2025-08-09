#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int lo = 0;
        int hi = m * n - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int row = mid / n;
            int col = mid % n;

            if(target == matrix[row][col]) return true;
            else if(target > matrix[row][col]) lo = mid + 1;
            else hi = mid - 1;

        }

        return false;

    }
};

int main() {
    
    return 0;
}