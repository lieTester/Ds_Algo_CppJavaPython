// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int makeCount(int S[], long long int coin, long long int ind, vector<vector<long long int>> &dp)
    {
        if (coin == 0)
            return 1;
        if (coin < 0 || ind < 0)
            return 0;
        if (dp[ind][coin] != -1)
            return dp[ind][coin];

        if (S[ind] <= coin)
        {
            dp[ind][coin] = makeCount(S, coin - S[ind], ind, dp) + makeCount(S, coin, ind - 1, dp);
        }
        else
        {
            dp[ind][coin] = makeCount(S, coin, ind - 1, dp);
        }
        return dp[ind][coin];
    }

    long long int count(int S[], int m, int n)
    {

        // not able to understand below code
        // long long count[n + 1] = {1};
        // for (int i = 1; i <= m; i++)
        // {

        //     for (int j = S[i - 1]; j <= n; j++)
        //     {
        //         count[j] += count[j - S[i - 1]];
        //     }
        // }
        // return count[n];

        // code here.
        vector<vector<long long int>> ans(m + 1, vector<long long int>(n + 1, -1));
        // below statement for recursive memoization
        // return makeCount(S, n, m - 1, ans);

        // below is top down dp
        for (int i = 0; i <= n; i++)
        {
            ans[0][i] = 0;
        }

        for (int i = 0; i <= m; i++)
        {
            ans[i][0] = 1;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (S[i - 1] <= j)
                {
                    ans[i][j] = ans[i][j - S[i - 1]] + ans[i - 1][j];
                }
                else
                {
                    ans[i][j] = ans[i - 1][j];
                }
            }
        }

        return ans[m][n];
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
} // } Driver Code Ends