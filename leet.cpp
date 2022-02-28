// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// same as
// https://leetcode.com/problems/smallest-string-with-swaps/submissions/

/**
 *
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    
    ListNode* partition(ListNode* head, int x) {
        ListNode* aPart= new ListNode(INT_MAX);
        ListNode* bPart= new ListNode(INT_MAX);
        ListNode* temp=head->next;
        
        if(head->val<x)aPart=head;
        else bPart=head;
        
        ListNode* firstHalf  = aPart;
        ListNode* secondHalf = bPart;
        
        while(temp){
            if(temp->val<x){
                aPart->next=temp;
                aPart=aPart->next;
            }else{
                bPart->next=temp;
                bPart=bPart->next;
            }
            temp=temp->next;
        }
        if(firstHalf->val==INT_MAX)firstHalf=firstHalf->next;
        else secondHalf=secondHalf->next;
        bPart->next=nullptr;
        aPart->next=secondHalf;
        
        return firstHalf;
    }
};
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution ob;

    ListNode *node6 = new ListNode(2);
    ListNode *node5 = new ListNode(5,node6);
    ListNode *node4 = new ListNode(2, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(4, node3);
    ListNode *node1 = new ListNode(1, node2);

    auto t = ob.partition(node1, 3);
    return 0;
}

// } Driver Code Ends