#include<bits/stdc++.h>
#include<vector>

using namespace std;

bool cmp(vector<int> &a , vector<int> &b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end() , cmp);

        vector<vector<int>> ans;

        int i = 1;

        vector<int> prev = intervals[0];

        while(i < n){
            int currstart = intervals[i][0];
            int currend = intervals[i][1];
            int prevstart = prev[0];
            int prevend = prev[1];

            if(currstart > prevend){
                ans.push_back(prev);
                prev = intervals[i];
            }else{
                prev[1] = max(currend , prevend);
            }
            i++;
        }

        ans.push_back(prev);

        return ans;
    }
};

int main() {
    
    return 0;
}