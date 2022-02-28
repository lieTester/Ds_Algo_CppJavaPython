// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// this one is better approch
class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string> &W, vector<string> &P)
    {
        unordered_map<int, int> mp; // { bitmask : frequency }
        vector<int> ans(size(P));

        // following function returns bitmask of a string
        auto getBitmask = [](string &s)
        {
            int bitmask = 0;
            for (auto c : s)
                bitmask |= 1 << c - 'a';
            return bitmask;
        };

        // generating bitmask for each word and filling in hashmap
        for (auto &word : W)
            mp[getBitmask(word)]++;
        // generate bitmask for each puzzle and enumerate over its subset

        for (int i = 0; auto &puzzle : P)
        {
            int mask = getBitmask(puzzle), cnt = 0, firstLetter = 1 << puzzle[0] - 'a';

            // https://cp-algorithms.com/algebra/all-submasks.html
            for (int submask = mask; submask; submask = (submask - 1) & mask)
            {
                /*
                In previous upproch we are calculating all that all the words containing first letter of puzzel
                we are checking puzzle mask & wordMask[i] and after this end operation it equals to wordsMask[i]
                means all the letter of word are in puzzel so we increase count

                but

                here we already make words mask map with count how many time this mak being made by diffrent words

                what we are doing here is whatever word mask we have we also check,
                puzzel mask with all submasks of this word mask now why because if that mask present in
                over major wordsMask map and (it setisfying the condiont first letter present in it and
                also submask of wordmask after & with puzzel mask ==>> become itself then its also over ans
                so whatever count present in worrdsMask add to count
                )





                */
                if (submask & firstLetter) // ensure 1st letter is present in submask to satisfy condition-1
                    cnt += mp[submask];    // add count of words having same bitmask as submask
            }
            ans[i++] = cnt;
        }
        return ans;
    }
};

// this one is good but high time complexity
class Solution
{
public:
    // making mask of word
    int makeMask(string word)
    {
        int mask = 0;
        for (char ch : word)
        {
            int bit = (ch - 'a');
            mask = mask | (1 << bit);
        }
        return mask;
    }
    vector<int> findNumOfValidWords(vector<string> words, vector<string> puzzles)
    {
        vector<int> wordsMasks[26];
        map<string, int> alreadyHave;
        vector<int> ans;
        int mask = 0;
        int count = 0;
        // here we are making mask of every word in wordslist
        // the mask make for the word and adding it every character of word index
        for (int i = 0; i < words.size(); i++)
        {

            if (alreadyHave.count(words[i]) == 0)
            {
                mask = makeMask(words[i]);
                alreadyHave[words[i]] = mask;
            }
            else
                mask = alreadyHave[words[i]];
            // why we make map because if we already added a mask to character in word
            // if character rpeate in word then we make repeat of it it can affect the ans
            map<int, int> visited;
            for (char ch : words[i])
            {
                int bit = (ch - 'a');
                // if we already added mask to particular characher then dont repeat
                if (visited.count(bit))
                    continue;
                visited[bit]++;
                wordsMasks[bit].push_back(mask);
            }
        }

        // now we get mask of every puzzel and traverse its first character mask in wordMasklist and check it each of them

        for (int i = 0; i < puzzles.size(); i++)
        {
            count = 0;
            if (alreadyHave.count(words[i]) == 0)
            {
                mask = makeMask(puzzles[i]);
                alreadyHave[puzzles[i]] = mask;
            }
            else
                mask = alreadyHave[puzzles[i]];

            int firstChar = puzzles[i][0] - 'a';

            for (int j = 0; j < wordsMasks[firstChar].size(); j++)
            {
                if ((mask & wordsMasks[firstChar][j]) == wordsMasks[firstChar][j])
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
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

    auto t = ob.findNumOfValidWords({"aaaa", "asas", "able", "ability", "actt", "actor", "access"},
                                    {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"});

    return 0;
}

// } Driver Code Ends