// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        if (n == 1) return n;
        while (true)
        {
            if (i <= j)
            {
                int mid = i+(j-i)/2;
                if ((mid == 1 && isBadVersion(mid) == true) || (isBadVersion(mid) == true && isBadVersion(mid-1) == false))
                    return mid;
                else if (isBadVersion(mid) == false && isBadVersion(mid+1) == true)
                    return mid+1;
                else if (isBadVersion(mid) == true)
                    j = mid-1;
                else if (isBadVersion(mid) == false)
                    i = mid+1;
            }
        }
    }
};
