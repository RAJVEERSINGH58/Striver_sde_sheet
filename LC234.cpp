#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// /**Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}    ListNode(int x, ListNode *next) : val(x), next(next) {}};
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        stack<int> s;

        ListNode* temp = head;
        string str = "";

        while(temp != NULL){
            str+=temp->val - '0';
            s.push(temp -> val);
            temp = temp -> next;
        }
        int i = 0;
        while(!s.empty()){
         
            if(s.top() !=(str[i++] + '0')){
                return 0;
            }
            s.pop();
        }
   return 1;

        
    }
};
