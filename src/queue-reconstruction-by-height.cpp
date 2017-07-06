// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int> > ans;
        vector<int> sorted;
        sort(people.begin(), people.end());
        int n = people.size();
        for (int i = 0; i < n; i++)
        {
            if (sorted.size() > 0) sort(sorted.begin(), sorted.end());
            for (int j = 0; j < people.size(); j++)
            {
                if (satisfies(sorted, people[j]))
                {
                    ans.push_back(people[j]);
                    people.erase(people.begin() + j);
                    break;
                }
            }
            sorted.push_back(ans.back().first);
        }
        return ans;
    }
private:
    bool satisfies(vector<int> &sorted, pair<int, int> &p)
    {
        int n = sorted.size();
        if (n == 0 && p.second == 0) return true;
        else if (n >= 1)
        {
            int i = 0, j = n-1, ans;
            while (true)
            {
                if (i > j)
                {
                    ans = j;
                    break;
                }
                else
                {
                    int mid = i + (j-i)/2;
                    if (sorted[mid] == p.first && mid > 0 && sorted[mid-1] < p.first) 
                    {
                        ans = mid-1;
                        break;
                    }
                    else if (sorted[mid] >= p.first) j = mid-1;
                    else if (sorted[mid] < p.first) i = mid+1;
                }
            }
            int n_elements = n-ans-1;
            if (n_elements == p.second) return true;
        }
        return false;
    }
};
