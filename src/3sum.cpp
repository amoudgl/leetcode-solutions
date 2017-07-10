// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<string> s;
        sort(nums.begin(), nums.end());
        int j, k, n = nums.size(), count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            j = i-1;
            k = i+1;
            if (nums[i] != nums[i-1]) count = 0;
            else if (nums[i] == nums[i-1]) count++;
            if (count < 2)
            {
                while (j >= 0 && k < n)
                {
                    long long int sum = nums[i] + nums[j] + nums[k];
                    if (sum > 0) j--;
                    else if (sum < 0) k++;
                    else if (sum == 0)
                    {
                        string str = to_string(nums[j]) + "," + to_string(nums[i]) + "," + to_string(nums[k]);
                        if (s.find(str) == s.end())
                        {
                            s.insert(str);
                        }
                        j--;
                        k++;
                    }
                }                
            }
        }
        vector<vector<int> > ans;
        for (auto p : s)
        {
            vector<int> temp;
            temp = parse(p);
            ans.push_back(temp);
        }
        return ans;
    }
private:
    vector<int> parse(string s)
    {
        vector<int> commas;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ',') commas.push_back(i);
        }
        vector<int> ans(3);
        ans[0] = stoi(s.substr(0, commas[0]));
        ans[1] = stoi(s.substr(commas[0]+1, commas[1]-commas[0]-1));
        ans[2] = stoi(s.substr(commas[1]+1, s.length()-commas[1]-1));
        return ans;
    }
};