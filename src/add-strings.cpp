// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() == 0) return num2;
        else if (num2.length() == 0) return num1;
        if (num1.length() < num2.length())
        {
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }
        int m = num1.length(), n = num2.length(), carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < m; i++)
        {
            int digit = (num1[i]-48 + ((i < n) ? num2[i]-48 : 0) + carry) % 10;
            carry = (num1[i]-48 + ((i < n) ? num2[i]-48 : 0) + carry) / 10;
            num1[i] = digit+48;
        }
        if (carry != 0) num1 += to_string(carry);
        reverse(num1.begin(), num1.end());
        return num1;
    }
};
