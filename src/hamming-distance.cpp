// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int hammingDistance(int x, int y) {
        string a, b;
        a = GetBitString(x);
        b = GetBitString(y);
        int distance = 0;
        for (int i = 0; i < 32; i++)
        {
            if (a[i] != b[i])
                distance++;
        }
        return distance;
    }
    string GetBitString(int x)
    {
        string a = "";
        while (x > 0)
        {
            int digit = x % 2;
            x = x/2;
            a = to_string(digit) + a;
        }
        string zeros;
        for (int i = 0; i < 32 - a.length(); i++)
        {
            zeros += "0";
        }
        a = zeros + a;
        return a;
    }
};
