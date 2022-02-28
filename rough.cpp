#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dvd(string s, int prtn, int indx, vector<vector<int>> &dp)
    {
        if (indx >= s.size())
            return 0;
        if (dp[indx][prtn] != -1)
            return dp[indx][prtn];

        int count = 0;
        if (prtn == 0)
        {
            while (indx < s.size())
            {
                if (s[indx] == 'S'){
                    count++;
                    break;
                }
                count += dvd(s, 2, indx, dp) + 1;
                indx++;
            }
            prtn=2;
        }
        while(indx<s.size()&&s[indx]!='S')indx++;
        count += dvd(s, prtn - 1, indx +1, dp);

        return dp[indx][prtn] = count;
    }
    int numberOfWays(string c)
    {
        int s = 0;
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] == 'S')
                s++;
        }
        if (s & 1 || s == 0)
            return 0;

        s = (s / 2) + 1; // these many pillars we can add
        vector<vector<int>> dp(c.size(), vector<int>(s + 1, -1));
        return dvd(c, 2, 0, dp);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;
    auto t = obj.numberOfWays("PPSPSP");
    return 0;
}