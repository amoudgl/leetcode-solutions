// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int i, j; 
        unordered_map<long long int, int> m;
        for (i = 0; i < A.size(); i++)
        {
            for (j = 0; j < B.size(); j++)
            {
                long long int sum = (long long int) A[i] + (long long int) B[j];
                if (m.find(sum) == m.end()) m[sum] = 1;
                else m[sum]++;
            }
        }
        int ans = 0;
        for (i = 0; i < C.size(); i++)
        {
            for (j = 0; j < D.size(); j++)
            {
                long long int sum = (long long int) C[i] + (long long int) D[j];
                if (m.find(-sum) != m.end())
                    ans += m[-sum];
                    
            }
        }
        return ans;
    }
};
