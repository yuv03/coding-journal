// class Solution {
// public:
//     int largestAltitude(vector<int>& gain) {
//         vector<int> alt(1,0);
//         for(int i=0; i<gain.size(); i++){
//             alt.push_back(alt[i]+gain[i]);
//         }
//         int max_alt = *max_element(alt.begin(), alt.end());
//         return max_alt;
//     }
// };

// Note: why you are using extra space here, it could be done without using extra space



class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int max_alt = 0;

        for(int i=0; i<gain.size(); i++){
            alt += gain[i];
            max_alt = max(max_alt, alt);
        }
        return max_alt;
    }
};