#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    bool dfs(vector<vector<int>>& graph , int node , unordered_map<int ,int>& mp , int color){

        for(auto neighbour : graph[node]){
            if(mp[neighbour] == color) return false;
            else if(mp[neighbour] == 0){
                int newcolor = (color == -1) ? -2 : -1;
                mp[neighbour] = newcolor;
                bool flag = dfs(graph , neighbour , mp , newcolor);
                if(flag == false) return false;
            }
        }

        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        unordered_map<int ,int> mp; // {node , color}
        int n = graph.size();

        for(int i = 0 ; i < n ; i++){
            for(int node : graph[i]){
                if(mp[node] != -1 && mp[node] != -2){
                    mp[node] = -1;
                    bool flag = dfs(graph , node , mp , -1);
                    if(flag == false) return false;
                }
            }
        }

        return true;

    }
};

int main() {
    
    return 0;
}