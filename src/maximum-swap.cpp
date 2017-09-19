// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length(), ans = num;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                swap(str[i], str[j]);
                ans = max(stoi(str), ans);
                swap(str[i], str[j]);
            }
        }
        return ans;
    }
    void swap(char &a, char &b)
    {
        char c = a;
        a = b;
        b = c;
    }
};
