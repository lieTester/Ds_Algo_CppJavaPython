#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(long long nums[], long long start, long long mid, long long end, long long &count)
    {
        // merge two sorted array concept work
        long long f = start, s = mid;
        vector<long long> temp;

        while (f < mid && s <= end)
        {
            if (nums[f] <= nums[s])
            {
                temp.push_back(nums[f++]);
            }
            else
            {
                count += (mid - f); // this is over answere
                temp.push_back(nums[s++]);
            }
        }
        while (f < mid)
        {
            temp.push_back(nums[f++]);
        }
        while (s <= end)
        {
            temp.push_back(nums[s++]);
        }
        f = 0;
        while (start <= end)
        {
            nums[start] = temp[f];
            ++start;
            ++f;
        }
    }
    void mergeSort(long long nums[], long long s, long long e, long long &tempcount)
    {
        if (s == e)
            return;
        long long mid = (s + e) / 2;
        if (s < e)
        {
            mergeSort(nums, s, mid, tempcount);
            mergeSort(nums, mid + 1, e, tempcount);
            merge(nums, s, mid + 1, e, tempcount);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long ans = 0;
        mergeSort(arr, 0, N - 1, ans);
        // for(int i=0;i<N;++i)cout<<arr[i]<<" ";
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;
    long long nums[] = {2, 4, 1, 3, 5};
    auto t = obj.inversionCount(nums, 5);
    cout << t;
    return 0;
}