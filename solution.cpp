#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    
    int getMaxLen(int val)
    {
        return val*21;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;
    vector<int> n2 = {1, -2, 3, -4, -5, 6};
    int val;
    cin>>val;
    cout << obj.getMaxLen(val);
    return 0;
}