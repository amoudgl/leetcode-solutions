// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        // return nums[n-k];
        vector<bool> check(n, true);
        pair<int, int> p;
        for (int i = 1; i <= k; i++)
        {
            p = FindKLargest(nums, check, 0, n-1);
            // cout << p.second << endl;
            check[p.first] = false;
        }
        return nums[p.first];
    }
    pair<int, int> FindKLargest(vector<int> &nums, vector<bool> &check, int i, int j)
    {
        if (j-i == 0)
        {
            if (check[i] == false)
                return make_pair(-1, INT_MIN);
            return make_pair(i, nums[i]);
        }
        if (j-i == 1)
        {
            if ((nums[i] >= nums[j] && check[i] == true && check[j] == true) || (check[i] == true && check[j] == false))
                return make_pair(i, nums[i]);
            else if ((nums[j] > nums[i] && check[i] == true && check[j] == true) || (check[j] == true && check[i] == false))
                return make_pair(j, nums[j]);
            else if (check[i] == false && check[j] == false)
                return make_pair(-1, INT_MIN);
        }
        int mid = i + (j-i)/2;
        auto p1 = FindKLargest(nums, check, i, mid);
        auto p2 = FindKLargest(nums, check, mid+1, j);
        if ((p1.second >= p2.second && p1.first != -1 && p2.first != -1) || (p1.first != -1 && p2.first == -1))
            return p1;
        else if ((p2.second > p1.second && p1.first != -1 && p2.first != -1) || (p1.first == -1 && p2.first != -1))
            return p2;
        else if (p1.first == -1 && p2.first == -1)
            return make_pair(-1, INT_MIN);
        return make_pair(-1, INT_MIN);
    }
    
};
