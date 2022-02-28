#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // arr: input array
    // n: size of array

    int minJumps(int arr[], int n)
    {
        vector<int> dp(n, INT_MAX);
        int ans = 0;
        int maxm = 0;
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxm = max(maxm, i + arr[i]);
            if (i == ans)
            {
                ans = maxm;
                count++;
            }
        }
        if (!count)
            return -1;
        return count;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;

    int ans[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    cout << obj.minJumps(ans, 11);

    return 0;
}