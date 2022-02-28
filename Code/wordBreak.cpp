// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void makeStnc(string s, string ans, int space, int indx, map<string, int> &liabilty, vector<string> &result)
    {
        // space is used only for check string length without space
        if (s.size() == (ans.size() - space))
        {
            result.push_back(ans);
            return;
        }
        if (indx == s.length())
            return;

        string temp;
        for (int i = indx; i < s.size(); i++)
        {
            temp += s[i];
            if (liabilty.count(temp))
            {
                // this condition only for not adding starting extra space at starting
                if (ans.size() == 0)
                {
                    makeStnc(s, temp, space, i + 1, liabilty, result);
                }
                else
                {
                    makeStnc(s, ans + " " + temp, space + 1, i + 1, liabilty, result);
                }
            }
        }
    }
    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        // code here

        vector<string> result;
        string ans;
        map<string, int> liabilty;
        for (int i = 0; i < dict.size(); i++)
        {
            liabilty[dict[i]] = i;
        }
        makeStnc(s, ans, 0, 0, liabilty, result);

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
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends