// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printSubsequence(string input, string output)
    {
        if (input.empty())
        {
            cout << output << endl;
            return;
        }

        printSubsequence(input.substr(1), output);
        output += input[0];
        printSubsequence(input.substr(1), output);
    }
};
// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1;
    string s2;
    cin >> s1 >> s2;
    Solution ob;
    string output = "";
    string input = "abcd";

    ob.printSubsequence(input, output);

    return 0;
} // } Driver Code Ends