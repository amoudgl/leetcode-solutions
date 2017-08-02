// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int magicalString(int n) {
        string x, y;
        x = "12";
        y = "1";
        int j = 1;
        int k = 0;
        while (x.length() < n)
        {
            if (y[k] == '1')
            {
                if (x[j] == '1')
                {
                    y += "2";
                    k++;
                }
                else if (x[j] == '2')
                {
                    y += "22";
                    k += 2;
                }
            }
            else if (y[k] == '2')
            {
                if (x[j] == '1')
                {
                    y += "1";
                    k++;
                }
                else if (x[j] == '2')
                {
                    y += "11";
                    k += 2;
                }                
            }
            x = y;
            j++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (x[i] == '1') ans++;
        return ans;
    }
};
