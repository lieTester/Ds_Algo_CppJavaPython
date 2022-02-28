#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxLength(int fn, int sn, int count, int indx, int lz)
    {
        if (count % 2 == 0)
        {
            if (lz)
                indx -= lz;

            return indx + 1;
        }

        return max(indx - fn, sn - lz);
    }

    int getMaxLen(vector<int> &nums)
    {
        int i = 0;
        int maxL = 0;
        // first negetive index
        int fN = -1;
        // last negetive index
        int sN = -1;
        // total negative count for checking odd or even
        int tNc = 0;
        // last zero to minus from sN
        int lZ = 0;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                maxL = max(maxL, maxLength(fN, sN, tNc, i - 1, lZ));
                fN = -1;
                sN = -1;
                tNc = 0;
                lZ = i;
            }

            if (nums[i] < 0)
            {
                tNc++;
                if (fN == -1)
                    fN = i;
                sN = i;
            }
        }
        maxL = max(maxL, maxLength(fN, sN, tNc, i - 1, lZ));
        return maxL;
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
    cout << obj.getMaxLen(n2);
    return 0;
}