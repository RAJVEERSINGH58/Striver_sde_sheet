#include <bits/stdc++.h>
#include <iostream>
using namespace std;


  // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

  if(head == NULL)
  return head;

  map<ListNode*, bool> visted;

  ListNode* temp = head;

  while(temp!=NULL){
    if(visted[temp]==true){
     return temp;
     
    }

    visted[temp] = true;

    temp = temp -> next;
  }
   return NULL;
        
    }
};
