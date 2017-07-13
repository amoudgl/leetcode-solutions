// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n, 0);
        int minjump = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dp[0] = 0;
                minjump = 0;
            }
            else 
            {
                minjump = findMinjump(stones, i, minjump, dp);
                dp[i] = findMaxjump(stones, i, dp);
            }
        }
        if (dp[n-1] == -1 && minjump == -1) return false;
        return true;
    }
private:
    int findMinjump(vector<int> &stones, int i, int minjump, vector<int> &dp)
    {
        if (minjump == stones[i]-stones[i-1]) return minjump;
        else if (minjump+1 == stones[i]-stones[i-1]) return minjump+1;
        else if (minjump-1 == stones[i]-stones[i-1]) return minjump-1;
        else
        {
            int j = i-1;
            int max = -1;
            while (j >= 0)
            {
                if (stones[i]-stones[j] >= dp[j]-1 && stones[i]-stones[j] <= dp[j]+1)
                {
                    if (stones[i]-stones[j] == dp[j]) max = dp[j];
                    else if (stones[i]-stones[j] == dp[j] + 1) max = dp[j] + 1;
                    else if (stones[i]-stones[j] == dp[j] - 1) max = dp[j] - 1;
                    break;
                }
                j--;
            }
            return max;            
        }
    }
    int findMaxjump(vector<int> &stones, int i, vector<int> &dp)
    {
        int j = i-1;
        int max = -1;
        while (j >= 0)
        {
            if (stones[i]-stones[j] >= dp[j]-1 && stones[i]-stones[j] <= dp[j]+1)
            {
                if (stones[i]-stones[j] == dp[j]) max = dp[j];
                else if (stones[i]-stones[j] == dp[j] + 1) max = dp[j] + 1;
                else if (stones[i]-stones[j] == dp[j] - 1) max = dp[j] - 1;
            }
            j--;
        }
        return max;
    }
};
