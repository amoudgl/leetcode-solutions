// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, k, f = 0, ans = 0, n = A.size();
        if (n == 0) return 0;
        for (int i = 0; i < n; i++)
        {
            f = f + i*A[i];
            sum += A[i];
        }
        int last = A[n-1];
        k = n-1;
        ans = f;
        while (1)
        {
            f = f + (sum-last) - (last*(n-1));
            ans = max(f, ans);
            k--;
            if (k >= 0) last = A[k];
            else break;
        }
        return ans;
    }
};
