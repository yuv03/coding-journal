class Solution {
public:
    int minFlips(int a, int b, int c) {
        vector<int> tempBit(33, 0);
        vector<int> vecA(33, 0);
        vector<int> vecB(33, 0);
        vector<int> vecC(33, 0);

        int temp = a | b;

        int i = 32;
        while (temp > 0 && i >= 0) {
            tempBit[i] = temp & 1; // store last bit
            temp = temp >> 1;      // shift right
            i--;
        }

        int j =32;
        while (c > 0 && j >= 0) {
            vecC[j] = c & 1; // store last bit
            c = c >> 1;      // shift right
            j--;
        }

        int k =32;
        while (a > 0 && k >= 0) {
            vecA[k] = a & 1; // store last bit
            a = a >> 1;      // shift right
            k--;
        }

        int l =32;
        while (b > 0 && l >= 0) {
            vecB[l] = b & 1; // store last bit
            b = b >> 1;      // shift right
            l--;
        }

        int m = 32;
        int count = 0;

        while(m>=0){
            if(vecC[m] == 1 && tempBit[m] == 0){
                count++;
            }
            else if (vecC[m] == 0 && tempBit[m] == 1){
                if(vecA[m]==1 && vecB[m]==1) count+=2;
                else count++;
            }
            m--;
        }
        return count;
    }
};