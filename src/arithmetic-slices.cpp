// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() <= 2)
            return 0;
        int diff, ans = 0, l, i;
        if (A[0]-A[1] == A[1]-A[2])
        {
            diff = A[1] - A[0];
            l = 3;
        }
        else 
        {
            diff = A[2] - A[1];
            l = 2;
        }
        for (i = 3; i < A.size(); i++)
        {
            if (A[i] - A[i-1] == diff)
                l++;
            else
            {
                ans += fun(l);
                l = 2;
                diff = A[i] - A[i-1];
            }
        }
        ans += fun(l);
        return ans;
    }
    int fun(int N)
    {
        if (N < 3)
            return 0;
        return ((N-2)*(N+1) - (N*(N+1))/2 + 3);
    }
};
