#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> check(nums1.begin(), nums1.end());
        sort(check.begin(), check.end());
        int n = nums1.size();
        long long ans, sum, dif;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans + abs(nums1[i] - nums2[i]);
        }
        sum = ans;

        for (int i = 0; i < nums1.size(); i++)
        {

            int dist = abs(nums1[i] - nums2[i]);
            int l = 0, h = n - 1;

            // Find the number closest to nums2[i].
            // The closer the element, the smaller the difference.
            // we couldv used uper lowr boud also
            while (l < h)
            {
                int m = l + (h - l) / 2;
                if (check[m] > nums2[i])
                {
                    h = m;
                }
                else
                {
                    l = m + 1;
                }
                dist = min(dist, abs(nums2[i] - check[m]));
            }
            dist = min(dist, abs(nums2[i] - check[l]));
            sum = min(sum, ans - abs(nums1[i] - nums2[i]) + dist);
        }
        return sum % 1000000007;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;
    vector<int> n1 = {2, 4, 6, 8, 10};
    vector<int> n2 = {2, 4, 6, 8, 10};
    cout << obj.minAbsoluteSumDiff(n1, n2);
    return 0;
}