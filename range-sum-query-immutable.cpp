class NumArray {
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        if (n > 0)
        {
            presum = vector<int> (n);
            presum[0] = nums[0];
            for (int i = 1; i < n; i++)
                presum[i] += (presum[i-1] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0)
            return presum[j];
        else
            return presum[j] - presum[i-1];
    }
private: 
    vector<int> presum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
