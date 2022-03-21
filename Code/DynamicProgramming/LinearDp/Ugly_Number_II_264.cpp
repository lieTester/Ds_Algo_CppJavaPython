#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> u(n);
        u[0] = 1;

        pair<int, vector<int *>> help;

        /*
            our algo is we want only the number that multiple of 2,3 or 5 so
            we make an array of n size and add 1 default init
            now, we make three index point i->2, j->3, k->5 initially all pointing to zero(0) index which has 1 at start,
            we take minm of  min(u[i]*2, u[j]*3,  u[k]*5);
            which one has minimum we add it to u[fill]=minm, and also increse the pointer of (2or3or5)<=>(i,j,k) by which we get minm,
            if the minmimun comes from more than 2 index point,
            for suppose i=2,u[2]=3,so u[i]*2=6 and j=1,u[1]=2,so u[j]*3=6  both give 6 so we increse both i and j index

        */
        for (int i = 0, j = 0, k = 0, fill = 1; fill < n; fill++)
        {
            help.first = u[i] * 2;
            help.second = {&i};
            if (u[j] * 3 <= help.first)
            {
                if (u[j] * 3 == help.first)
                    help.second.push_back(&j);
                else
                {
                    help.first = u[j] * 3;
                    help.second = {&j};
                }
            }
            if (u[k] * 5 <= help.first)
            {
                if (u[k] * 5 == help.first)
                    help.second.push_back(&k);
                else
                {
                    help.first = u[k] * 5;
                    help.second = {&k};
                }
            }

            // we make vector of pointer although to access that pointer we 0 index than its gives us the pointer we want
            for (auto it : help.second)
                it[0]++;
            u[fill] = help.first;
        }
        return u[n - 1];
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution obj;

    auto t = obj.nthUglyNumber(10);
    return 0;
}