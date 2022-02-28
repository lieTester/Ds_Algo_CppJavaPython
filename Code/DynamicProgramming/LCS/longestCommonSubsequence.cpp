#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {

        int n = text1.length();
        int m = text2.length();

        int dp[n + 1][m + 1];

        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;

        //  0 0 0 0 0 0
        //  0
        //  0   making this structure by just above and below loop
        //  0   becuse of the condition if t1[i]=t2[j]
        //  0   then dp[i][j] =dp[i-1][j-1]+1  // for specially for starting line
        //  0

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;
    string a1 = "abcde";
    string a2 = "ace";
    cout << obj.longestCommonSubsequence(a1, a2);
    return 0;
}