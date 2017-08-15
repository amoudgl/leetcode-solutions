// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> output;
        for (int i = 0; i < input.length(); i++)
        {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*')
            {
                for (int a : diffWaysToCompute(input.substr(0, i)))
                {
                    for (int b : diffWaysToCompute(input.substr(i+1)))
                    {
                        if (c == '+') output.push_back(a+b);
                        else if (c == '-') output.push_back(a-b);
                        else if (c == '*') output.push_back(a*b);
                    }
                }
            }
        }
        if (output.size() == 0) return vector<int> {stoi(input)};
        return output;
    }
};
