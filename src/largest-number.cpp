// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    static bool comp(int a, int b)
    {
        string t1 = to_string(a)+to_string(b);
        string t2 = to_string(b)+to_string(a);
        if (t2 >= t1) return false;
        return true;
    }
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0) return "";
        sort(nums.begin(), nums.end(), comp);
        string ans;
        int flag = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0) flag = 1;
            if (flag)
                ans += to_string(nums[i]);
        }
        if (ans.length() == 0) return "0";
        return ans;
    }
};
