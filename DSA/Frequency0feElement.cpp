#include <bits/stdc++.h>
using namespace std;

vector<int> getFrequencies(vector<int> &v)
{
    unordered_map<int, int> mp;
    for (auto it : v)
    {
        mp[v[it]]++;
    }

    int mostFreq = INT_MIN;
    int leastFreq = INT_MAX;
    int mostFreqElement;
    int leastFreqElement;

    for (auto it : mp)
    {
        if (it.second >= mostFreq)
        {
            if (it.second == mostFreq)
            {
                mostFreqElement = min(mostFreqElement, it.first);
            }
            else
            {
                mostFreqElement = it.first;
            }
            mostFreq = it.second;
        }
        if (it.second <= leastFreq)
        {
            if (it.second <= leastFreq)
            {
                if (it.second == leastFreq)
                {
                    leastFreqElement = min(leastFreqElement, it.second);
                }
                else
                {
                    leastFreqElement = it.first;
                }
                leastFreq = it.second;
            }
        }
    }
    return {mostFreqElement, leastFreqElement};
}
int main()
{
    vector<int> input = {1, 2, 2, 2, 4};
    vector<int> result = getFrequencies(input);
    cout << "Most Frequent: " << result[0] << endl;
    cout << "Least Frequent: " << result[1] << endl;
    return 0;
}