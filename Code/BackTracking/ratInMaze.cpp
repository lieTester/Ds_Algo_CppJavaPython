// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    void read(vector<vector<int>> &M, vector<vector<int>> &dp, vector<string> &ans, int m, int n, string temp)
    {

        if (m < 0 || n < 0 || m >= M.size() || n >= M.size())
            return;
        if (dp[m][n] || M[m][n] == 0)
            return;

        if (m == M.size() - 1 && n == M.size() - 1)
        {
            ans.push_back(temp);
        }

        dp[m][n] = 1;

        read(M, dp, ans, m + 1, n, temp + 'D');
        read(M, dp, ans, m - 1, n, temp + 'U');
        read(M, dp, ans, m, n + 1, temp + 'R');
        read(M, dp, ans, m, n - 1, temp + 'L');
        dp[m][n] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<string> result;

        read(m, dp, result, 0, 0, "");

        return result;
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
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends