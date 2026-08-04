class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int sz = flowerbed.size();
        int c = 0;
        int count = n;

        int i = 0;

        while (i < sz) {

            if (flowerbed[i] == 0) {

                bool left = (i == 0 || flowerbed[i - 1] == 0);
                bool right = (i == sz - 1 || flowerbed[i + 1] == 0);

                if (left && right) {
                    flowerbed[i] = 1;
                    count--;
                }
            }

            if (count <= 0)
                return true;

            i++;
        }

        return false;
    }
};