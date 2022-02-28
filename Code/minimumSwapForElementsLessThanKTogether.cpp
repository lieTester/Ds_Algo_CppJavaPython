#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // main objective of this program is its making a window of all elements together
    // those are lesser the or = k and by using bad and good we try to achive where in
    // entire array it should be best fit for minmum swap
    int minSwap(int arr[], int n, int k)
    {
        int good = 0;
        int bad = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
                good++;
        }
        for (int i = 0; i < good; i++)
        {
            if (arr[i] > k)
                bad++;
        }
        int mn = bad;

        int i = 0, j = good;
        while (j < n)
        {
            if (arr[i] > k)
                bad--;
            if (arr[j] > k)
                bad++;
            mn = min(mn, bad);

            i++;
            j++;
        }

        return mn;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;
    int a[] = {6, 3, 5, 7, 0, 8, 1, 4, 9, 2};
    vector<string> ans;
    obj.minSwap(a, 10, 2);
    for (auto i : a)
    {
        cout << i << " ";
    }

    return 0;
}