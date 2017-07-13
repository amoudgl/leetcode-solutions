// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    Solution(vector<int> nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums;
        vector<int> ans;
        nums = original;
        for (int i = 0; i < original.size(); i++)
        {
            int randomIndex = rand() % nums.size();
            ans.push_back(nums[randomIndex]);
            nums.erase(nums.begin() + randomIndex);
        }
        return ans;
    }
private:
    vector<int> original;    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
