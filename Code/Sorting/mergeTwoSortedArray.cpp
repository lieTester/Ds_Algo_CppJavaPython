#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortArr(vector<int> &arr1, vector<int> &arr2)
    {
        int f = 0, s = 0, temp = 0;
        while (f < arr1.size() && s < arr2.size())
        {
            if (arr1[f] > arr2[s])
            {
                swap(arr1[f], arr2[s]);
            }
            temp = 1;
            while (temp < arr2.size() && arr2[temp] < arr2[temp - 1])
            {
                swap(arr2[temp], arr2[temp - 1]);
                temp++;
            }

            f++;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;
    vector<int> a = {1, 4, 7, 8, 10};
    vector<int> b = {2, 3, 9};
    obj.shortArr(a, b);
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : b)
    {
        cout << i << " ";
    }
    return 0;
}