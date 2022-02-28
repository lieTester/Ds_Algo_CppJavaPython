// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.

 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        // you code it but you are not quit shure  so try again
        if (head == nullptr || k == 1)
            return head;

        ListNode *curr = head;
        ListNode *lastElemOfThisGroup = head;
        ListNode *lastElemOfPrevGroup = nullptr;

        int t_k = 1;
        while (t_k != k && head)
        {
            head = head->next;
            t_k++;
        }
        if (head == nullptr)
            return curr;

        t_k = 1;

        while (lastElemOfThisGroup)
        {

            lastElemOfThisGroup = lastElemOfThisGroup->next;
            t_k++;
            if (t_k == k && lastElemOfThisGroup)
            {

                ListNode *firstElemOfNextGroup = lastElemOfThisGroup->next;
                ListNode *firstElemofCurrGroup = curr;
                ListNode *next = nullptr;
                ListNode *prev = nullptr;
                lastElemOfThisGroup->next = nullptr;

                while (curr)
                {
                    // its just simple reverse of linked list
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                if (lastElemOfPrevGroup)
                    lastElemOfPrevGroup->next = prev;
                else
                    firstElemofCurrGroup->next = firstElemOfNextGroup;

                // now here first element of current group is being reverse,
                // so it becomes last element of present k group
                lastElemOfPrevGroup = firstElemofCurrGroup;
                curr = firstElemOfNextGroup;
                lastElemOfThisGroup = firstElemOfNextGroup;
                t_k = 1;
            }
        }
        // it means that if current in non empty then last group is not able to form group size of k
        // so simply add it at end of the previous group
        if (curr && lastElemOfPrevGroup)
            lastElemOfPrevGroup->next = curr;

        return head;
    }
};
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution ob;
    //[5,2,6,3,9,1,7,3,8,4]
    // ListNode *n9 = new ListNode(10, nullptr);
    // ListNode *n8 = new ListNode(9, n9);
    // ListNode *n7 = new ListNode(8, n8);
    // ListNode *n6 = new ListNode(7, n7);
    // ListNode *n5 = new ListNode(6, n6);
    ListNode *n4 = new ListNode(5, nullptr);
    ListNode *n3 = new ListNode(4, n4);
    ListNode *n2 = new ListNode(3, n3);
    ListNode *n1 = new ListNode(2, n2);
    ListNode *n0 = new ListNode(1, n1);
    auto t = ob.reverseKGroup(n0, 2);

    return 0;
}

// } Driver Code Ends