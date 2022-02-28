#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums, int start, int mid, int end)
    {
        // merge two sorted array concept work
        int f = start, s = mid, temp = 0;
        while (f < mid && s < end + 1)
        {
            if (nums[f] > nums[s])
            {
                swap(nums[f], nums[s]);
            }
            temp = mid + 1;
            while (temp < end + 1 && nums[temp] < nums[temp - 1])
            {
                swap(nums[temp], nums[temp - 1]);
                temp++;
            }

            f++;
        }
    }
    void mergeSort(vector<int> &nums, int s, int e)
    {
        if (s == e)
            return;
        int mid = (s + e) / 2;
        if (s < e)
        {
            mergeSort(nums, s, mid);
            mergeSort(nums, mid + 1, e);
            merge(nums, s, mid + 1, e);
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;
    vector<int> a = {6, 3, 5, 7, 0, 8, 1, 4, 9, 2};
    vector<string> ans;
    obj.mergeSort(a, 0, a.size() - 1);
    for (auto i : a)
    {
        cout << i << " ";
    }

    return 0;
}