class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i < n-1 && nums[i] == 0)
            {
                int j = i-1;
                while (j >= 0 && nums[j]+j <= i)
                    j--;
                if (j < 0) return false;
            }
            else if (i == n-1 && nums[i] == 0)
            {
                int j = i-1;
                while (j >= 0 && nums[j]+j < i)
                    j--;
                if (j < 0) return false;                
            }
        }
        return true;
    }
};
