// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        f(0, target, 0, candidates, v);
        return ans;
    }
    void f(int sum, int target, int k, vector<int>& candidates, vector<int> v)
    {
        if (k >= candidates.size())
            return;
        vector<int> temp = v;
        int prev = sum;
        while (1)
        {
            sum += candidates[k];
            v.push_back(candidates[k]);
            if (sum == target) ans.push_back(v);
            else if (sum < target)
                f(sum, target, k+1, candidates, v);
            else break;
        }
        v = temp;
        sum = prev;
        f(sum, target, k+1, candidates, v); 
    }
private:
    vector<vector<int>> ans;
};
