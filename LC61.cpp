#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//  Definition for singly-linked list.
  struct ListNode {     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rev(ListNode* head , int n){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while(curr != NULL && (n--)){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;

    }
    int size(ListNode* head){
        int count = 0;
        while(head != NULL)
        {
            count++;
            head = head -> next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(k==0 or head == NULL) return head;

        ListNode* temp1 = head;
        ListNode* temp2 = head;

        int n = size(head);
        k = k % n;

        int part = n - k;

        while(part--){
            temp2 = temp2 -> next;
        }

        ListNode* f = rev(temp1 , n - k);
        ListNode* l = rev(temp2 , k );

        ListNode* t = f;

        while(t -> next != NULL){
            t=t->next;
        }
        t-> next = l;

        return rev(f,n);
        
    }};
