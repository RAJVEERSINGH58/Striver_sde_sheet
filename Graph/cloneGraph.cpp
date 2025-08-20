#include<bits/stdc++.h>
#include<vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> nodeRegister;

    void dfs(Node* clone , Node* actual){
        for(auto neighbor : actual->neighbors){
            if(not nodeRegister[neighbor->val]){
                Node* newnode = new Node(neighbor->val);
                nodeRegister[newnode->val] = newnode;
                clone->neighbors.push_back(newnode);
                dfs(newnode , neighbor);
            } else{
                clone->neighbors.push_back(nodeRegister[neighbor->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        nodeRegister.resize(110,NULL);
        Node* clone = new Node(node->val);
        nodeRegister[clone->val] = clone;
        dfs(clone , node);
        return clone;
        
    }
};

int main() {
    
    return 0;
}