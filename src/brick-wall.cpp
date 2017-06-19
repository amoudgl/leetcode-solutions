// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long int, int> m;
        int ans = 0;
        for (int i = 0; i < wall.size(); i++)
        {
            long long int sum = 0;
            for (int j = 0; j < wall[i].size()-1; j++)
            {
                sum += (long long int) wall[i][j];
                if (m.find(sum) == m.end()) m[sum] = 1;
                else m[sum]++;
                if (m[sum] > ans) ans = m[sum];
            }
        }
        return wall.size()-ans;
    }
};
