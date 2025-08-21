#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
  public:

    void dfs(int node , vector<int> adj[] , unordered_set<int>& vis, vector<int>& ans
){
      if(vis.count(node)) return;
      ans.push_back(node);
      vis.insert(node);

      for(int neigh : adj[node]){
        if(! vis.count(neigh)){
          dfs(neigh , adj , vis ,ans);
        }
      }

    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
     
      unordered_set<int> vis;
      vector<int> ans;

      dfs(0 , adj , vis ,ans);

      return ans;

    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
      unordered_set<int> vis;
      queue<int> q;
      q.push(0);
      vis.insert(0);
      vector<int> ans;

      while(! q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int neigh : adj[node]){
          if(! vis.count(neigh)){
            q.push(neigh);
            vis.insert(neigh);
          }
        }

      }

      return ans;

    }
};


int main() {
    
    return 0;
}