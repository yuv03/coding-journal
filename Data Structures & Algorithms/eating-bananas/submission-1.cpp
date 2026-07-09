class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans_min = INT_MAX;
        bool flag = false;

        while(start <= end){
            int mid = start + (end - start)/2;
            int count = 0;
            for(int i=0; i<piles.size(); i++){
                count += (piles[i] + mid - 1) / mid;
                // int temp = piles[i];
                // if(temp <= mid) count++;
                // else{
                //     while(temp > 0){
                //         count++;
                //         temp -= mid;
                //     }
                // }
            }

            if(count > h) start = mid+1;
            else if (count<=h) {
                flag = true;
                end = mid-1;
                ans_min = min(ans_min, mid);
            }

        }
        if(flag) return ans_min;
        else return -1;
    }
};
