// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
            m = min(nums[i], m);
        int moves = 0;
        for (int i = 0; i < nums.size(); i++)
            moves += (nums[i]-m);
        return moves;
    }
};
