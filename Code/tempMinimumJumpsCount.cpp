#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr: input array
    // n: size of array
    int jump(int arr[], int size, int index, vector<int> &dp)
    {
        if (!arr[index])
            return 0;

        if (index + arr[index] >= size - 1)
            return 1;


        int cost = INT_MAX;
        for (int i = index; i < index + arr[index] && i < size - 1; i++)
        {
            int temp = jump(arr, size, i + 1, dp);
            if(temp){
                cost = min(cost, temp) + 1;
            }else{
                return 0;
            }
                
        }
        return cost;
    }

    int minJumps(int arr[], int n)
    {
        vector<int> dp(n, INT_MAX);
        if (arr[0] == 0)
            return -1;

        dp[0] = jump(arr, n, 0, dp);

        if (dp[0] == INT_MAX || !dp[0])
            return -1;

        return dp[0];
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;

    int ans[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    cout << obj.minJumps(ans, 11);
    return 0;
}