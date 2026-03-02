class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = INT_MAX;
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        while(start <= end){
            int mid = start + (end-start)/2;
            long long hours = 0;
            for(int i=0; i<piles.size(); i++){
                hours += (piles[i]+mid-1)/mid;  // if piles[i] is perfectly divisible by mid then the (mid-1)/mid will not have any effect on the hours, but if not perfectly divisible then we want the hour to increase by 1 so that it will do. 
            }
            if(hours <= h) {
                min_speed = min(mid, min_speed);
                end = mid-1;
            }
            else start = mid+1;
        }
        return min_speed;
    }
};