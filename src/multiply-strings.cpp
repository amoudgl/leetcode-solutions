// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        if (num1.length() < num2.length())
        {
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }
        string a, zeros, b;
        int carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num2.length(); i++)
        {
            for (int j = 0; j < num1.length(); j++)
            {
                int digit = (((num2[i]-48) * (num1[j]-48)) + carry) % 10;
                carry = (((num2[i]-48) * (num1[j]-48)) + carry) / 10;
                b += to_string(digit);
            }
            if (carry != 0) b += to_string(carry);
            b = zeros + b;
            a = StringAdd(a, b);
            b = "";
            zeros += "0";
            carry = 0;
        }
        reverse(a.begin(), a.end());
        return a;
    }
    string StringAdd(string a, string b)
    {
        if (a.length() == 0) return b;
        if (b.length() == 0) return a;
        if (a.length() < b.length())
        {
            string temp = a;
            a = b;
            b = temp;
        }
        int carry = 0;
        string ans;
        for (int i = 0; i < a.length(); i++)
        {
            if (i < b.length())
            {
                int digit = ((a[i]-48) + (b[i]-48) + carry) % 10;
                carry = ((a[i]-48) + (b[i]-48) + carry) / 10;
                ans += to_string(digit);
            }
            else
            {
                int digit = ((a[i]-48) + carry) % 10;
                carry = ((a[i]-48) + carry) / 10;
                ans += to_string(digit);
            }
        }
        if (carry != 0) ans += to_string(carry);
        return ans;
    }
};
