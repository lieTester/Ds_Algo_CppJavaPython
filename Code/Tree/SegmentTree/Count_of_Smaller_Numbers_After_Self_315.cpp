#include <bits/stdc++.h>
using namespace std;
class segtree
{
public:
    int start, end, sum;
    segtree *right, *left;
    segtree(int s, int e)
    {
        start = s;
        end = e;
        sum = 0;
    }
};
class solution
{
private:
    segtree *root;

public:
    vector<int> countSmaller(vector<int> nums)
    {
        int n = nums.size();
        if (n == 0)
            return {};
        int minm = INT_MAX;
        int maxm = INT_MIN;
        vector<int> ans(n, 0);
        for (auto i : nums)
        {
            minm = min(minm, i);
            maxm = max(maxm, i);
        }
        root = build(minm, maxm);
        minm = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            update(nums[i], root);
            minm = min(minm, nums[i]);
            ans[i] = getAns(minm, nums[i] - 1, root);
        }

        return ans;
    }
    segtree *build(int l, int r)
    {
        if (l > r)
            return nullptr;

        segtree *node = new segtree(l, r);
        if (r == l)
            return node;

        int mid = l + (r - l) / 2;
        node->left = build(l, mid);
        node->right = build(mid + 1, r);
        return node;
    }
    void update(int indx, segtree *node)
    {
        if (node->start == node->end && node->start == indx)
        {
            node->sum += 1;
            return;
        }
        int mid = node->start + (node->end - node->start) / 2;

        if (indx <= mid)
            update(indx, node->left);
        else
            update(indx, node->right);
        node->sum = (node->right ? node->right->sum : 0) + (node->left ? node->left->sum : 0);
    }
    int getAns(int l, int r, segtree *node)
    {
        if (l > r || node == nullptr)
            return 0;
        if (node->start == l && node->end == r)
            return node->sum;

        int mid = node->start + (node->end - node->start) / 2; // this condition is important inall three to save us from stack overflow

        if (r <= mid)
            return getAns(l, r, node->left);
        else if (l > mid)
            return getAns(l, r, node->right);

        return getAns(l, mid, node->left) + getAns(mid + 1, r, node->right);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution obj;

    auto t = obj.countSmaller({2, 0, 1});
    for (auto &&i : t)
    {
        cout << i << " ";
    }

    return 0;
}