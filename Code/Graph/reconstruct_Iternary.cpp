// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<string, vector<string>> adj;
    vector<string> ans;
    bool dfs(string src, int n)
    {

        if (ans.size() == n)
            return true;

        if (adj.count(src) == 0)
            return false;

        map<string, vector<string>> temp = adj;

        for (int i = 0; i < temp[src].size(); i++)
        {

            ans.push_back(temp[src][i]);

            adj[src].erase(adj[src].begin());

            if (adj[src].size() == 0)
                adj.erase(src);

            if (dfs(ans.back(), n))
                return true;
            adj[src].push_back(temp[src][i]);
            ans.pop_back();
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>> tickets)
    {
        // its like we have to always start from JFK then travel all paths but in lexicographical order
        // now the idea is first we have to make adjacensy list
        // for evert src append its destination now the problem is we have to travel in lexicographical,
        // so we have to sort the destination list of every src node,
        // so sort the tickets vector on key but if key is same then sort them with value.
        // for eg:-["JFK","SFO"],["JFK","ATL"]=> in this both key are same sort them with value so the ATL comes first.

        // inbuilt sort the way we want
        sort(tickets.begin(), tickets.end());

        for (auto i : tickets)
        {
            adj[i[0]].push_back(i[1]);
        }
        ans.push_back("JFK");
        bool t = dfs("JFK", tickets.size() + 1);
        return ans;
    }
};
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution ob;

    auto t = ob.findItinerary({{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}});
    return 0;
}

// } Driver Code Ends