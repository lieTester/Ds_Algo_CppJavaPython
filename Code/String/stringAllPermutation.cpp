#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;
    string a = "abcd";
    vector<string> ans;
    ans = obj.permutr(a);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}