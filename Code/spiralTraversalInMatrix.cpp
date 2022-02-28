// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        int tp, rg, bt, lf;
        tp = 0;
        lf = 0;
        bt = r;
        rg = c;
        int i = 0, j = -1;
        vector<int> ans;
        // major thought is that every time left to rigth if its from top we plus top to 1
        // because when we traverse column wise from bottom to top so we dont visit already
        // visited element of visited row;

        // same idea for bottom we -1
        // left +1
        // right -1
        while (tp < bt && lf < rg)
        {

            // why to use if condition when while work accordingly,
            // its because the top,right,bottom and left  elemts decrement and increament
            // they increament and decreament even we dont enter in loop

            if (j + 1 < rg)
            {
                while (j + 1 < rg)
                    ans.push_back(matrix[i][++j]);
                tp++;
            }

            // why these tp>=bt and lf>=rg condition its because if dont use one of the if condition
            // is some get correct then we loose our answer check by debug
            if (tp >= bt)
                break;

            if (i + 1 < bt)
            {
                while (i + 1 < bt)
                    ans.push_back(matrix[++i][j]);
                rg--;
            }

            if (lf >= rg)
                break;

            if (j - 1 >= lf)
            {
                while (j - 1 >= lf)
                    ans.push_back(matrix[i][--j]);
                bt--;
            }

            if (tp >= bt)
                break;

            if (i - 1 >= tp)
            {
                while (i - 1 >= tp)
                    ans.push_back(matrix[--i][j]);
                lf++;
            }
        }

        return ans;
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
