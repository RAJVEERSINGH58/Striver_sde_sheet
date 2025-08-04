#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int dp[30005][2];
    int f(vector<int>& prices , int i , bool on){
        if(i ==prices.size()) return 0;
        if(dp[i][on]!= -1) return dp[i][on];
        int ans = INT_MIN;
        //avoid
        ans = f(prices , i+1 , on);
        //not avoid
        if(on){
            ans = max(ans , prices[i] + f(prices,i+1,false));
        }
        else{
            ans = max(ans ,  f(prices,i+1,true) - prices[i] );
        }
        return dp[i][on] = ans;

    }

    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof dp);
        return f(prices , 0 , false);
    }
};

int main() {
    
    return 0;
}