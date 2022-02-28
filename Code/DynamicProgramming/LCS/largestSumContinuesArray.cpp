#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {

        //  Your code here kadane's algorithm
        //  why we choose ans=arr[0] because may be entire array is -ve then answer is zero always
        //  although answer should be max sum even if its negetive
        int ans = arr[0], largest = 0;
        for (int i = 0; i < n; i++)
        {
            largest += arr[i];
            ans = max(largest, ans);
            if (largest < 0)
                largest = 0;
        }
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
    int ans[] = {1, 2, 3, -2, 5};

    cout << obj.maxSubarraySum(ans, 5);

    return 0;
}