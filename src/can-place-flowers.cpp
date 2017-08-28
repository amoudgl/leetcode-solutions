// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, N = flowerbed.size();
        for (int i = 0; i < flowerbed.size(); i++)
        {    
            if (flowerbed[i] == 0)
            {
                int check = 1;
                if (i > 0 && flowerbed[i-1] == 1) check = 0;
                if (i+1 < N && flowerbed[i+1] == 1) check = 0;
                flowerbed[i] = check;
                if (check == 1) count++;
            }   
        }
        if (count >= n) return true;
        return false;
    }
};
