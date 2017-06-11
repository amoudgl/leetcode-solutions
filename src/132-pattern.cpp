// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int tempmin = INT_MAX;
        int tempmax = INT_MIN;
        vector<pair<int, int>> st;
        int j = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < tempmin)
            {
                tempmin = nums[i];
                tempmax = INT_MIN;
            }
            else if (nums[i] > tempmax)
            {
                tempmax = nums[i];
            }
            int k = j;
            while (k >= 0)
            {
                if (nums[i] > st[k].second)
                    k--;
                else if (nums[i] > st[k].first && nums[i] < st[k].second)
                    return true;
                else break;
            }
            if (j == -1 || (tempmin <= st[j].first && tempmax > tempmin))
            {
                if (j == -1 && tempmin < tempmax)
                {
                    j++;
                    st.push_back(make_pair(tempmin, tempmax));
                }
                else if (j != -1 && st[j].first == tempmin && st[j].second < tempmax)
                {
                    st[j].second = tempmax;
                }
                else if (j != -1 && st[j].first > tempmin && st[j].second < tempmax)
                {
                    st[j].first = tempmin;
                    st[j].second = tempmax;
                }
                else if (j != -1 && st[j].first > tempmin && tempmax <= st[j].second)
                {
                    j++;
                    st.push_back(make_pair(tempmin, tempmax));
                }
            }
        }
        return false;
    }
};
