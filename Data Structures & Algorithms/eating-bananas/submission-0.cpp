class Solution {
public:
    long long eatspeed(vector<int>& piles, int k) {
        long long s = 0;
        for (int i = 0; i < piles.size(); i++) {
            s += (piles[i] + k - 1) / k; // Integer ceiling division
        }
        return s;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxpile = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxpile = max(maxpile, piles[i]);
        }

        int i = 1; // Minimum eating speed is 1
        int ans = maxpile;

        while (i <= maxpile) {
            int mid = i + (maxpile - i) / 2;

            if (eatspeed(piles, mid) > h) {
                i = mid + 1;
            } else {
                ans = mid;
                maxpile = mid - 1;
            }
        }

        return ans;
    }
};

