// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y, distance = 0;
        while (z > 0)
        {
            distance += z % 2;
            z = z/2;
        }
        return distance;
    }
};
