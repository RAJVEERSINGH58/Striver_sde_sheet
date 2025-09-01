#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    vector<int> dx = {1 , 0 , -1 , 0};
    vector<int> dy = {0 , 1 , 0 , -1};

    int m , n;
    bool isSafeIndex(vector<vector<char>>& grid , int i , int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    void dfs(vector<vector<char>>& grid , int i , int j){

        if(! isSafeIndex(grid, i , j) || grid[i][j] == '0') return;

        grid[i][j] = '0';

        for(int k = 0 ; k < 4 ; k++){
            dfs(grid , i + dx[k] , j + dy[k]);
        }

        return;

    }

    int numIslands(vector<vector<char>>& grid) {
        int cc = 0;

        m = grid.size();
        n = grid[0].size();

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){
                    dfs(grid , i , j);
                    cc++;
                }
            }
        }

        return cc;

    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int cc = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == '0') continue;
                cc++;
                grid[i][j] = '0'; 
                queue<pair<int , int>> qu;
                qu.push({i , j});
                while(! qu.empty()){
                    auto curr = qu.front();
                    qu.pop();
                    int currRow = curr.first;
                    int currCol = curr.second;
                    if(currRow - 1 >= 0 and grid[currRow - 1][currCol] == '1'){
                        qu.push({currRow - 1 , currCol});
                        grid[currRow - 1][currCol] = '0';
                    }

                    if(currCol - 1 >= 0 and grid[currRow][currCol - 1] == '1'){
                        qu.push({currRow , currCol - 1});
                        grid[currRow][currCol - 1] = '0';
                    }

                    if(currRow + 1 < row and grid[currRow + 1][currCol] == '1'){
                        qu.push({currRow + 1 , currCol});
                        grid[currRow + 1][currCol] = '0';
                    }

                    if(currCol + 1 < col and grid[currRow][currCol + 1] == '1'){
                        qu.push({currRow , currCol + 1});
                        grid[currRow][currCol + 1] = '0';
                    }
                }
            }
        }
        return cc;
    }
};

int main() {
    
    return 0;
}