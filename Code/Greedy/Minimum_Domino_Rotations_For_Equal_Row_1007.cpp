#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // your code but not good enough
    int minDominoRotations(vector<int> tops, vector<int> bottoms)
    {
        unordered_map<int, vector<int>> tpf, btf;
        pair<int, int> tp, bt;
        tp = bt = {INT_MIN, INT_MIN};

        for (int i = 0; i < tops.size(); i++)
        {
            tpf[tops[i]].push_back(i);
            btf[bottoms[i]].push_back(i);
            tp = max(tp, {tpf[tops[i]].size(), tops[i]});
            bt = max(bt, {btf[bottoms[i]].size(), bottoms[i]});
        }

        // max freq found in top
        if (tp.first > bt.first)
        {
            for (int i = 0, j = 0; i < bottoms.size(); i++)
            {
                if (j < tpf[tp.second].size() && tpf[tp.second][j] == i)
                    j++;
                else if (bottoms[i] != tp.second)
                    return -1;
            }
            return tops.size() - tp.first;
        }
        else if (tp.first < bt.first)
        { // max freq found in bottom
            for (int i = 0, j = 0; i < tops.size(); i++)
            {
                if (j < btf[bt.second].size() && btf[bt.second][j] == i)
                    j++;
                else if (tops[i] != bt.second)
                    return -1;
            }
            return tops.size() - bt.first;
        }
        else
        { // both have elements and equal freq
            int i, j;
            for (i = 0, j = 0; i < tops.size(); i++)
            {
                if (j < btf[bt.second].size() && btf[bt.second][j] == i)
                    j++;
                else if (tops[i] != bt.second)
                    break;
            }
            if (i == tops.size())
                return tops.size() - tp.first;
            for (i = 0, j = 0; i < tops.size(); i++)
            {
                if (j < btf[bt.second].size() && btf[bt.second][j] == i)
                    j++;
                else if (tops[i] != bt.second)
                    return -1;
            }
            return tops.size() - bt.first;
        }

        return -1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;

    auto t = obj.minDominoRotations({2, 1, 2, 4, 2, 2}, {5, 2, 6, 2, 3, 2});
    cout << t;
    return 0;
}