class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;
        for(int i = 0; i < spells.size(); i++){
            int start = 0;
            int end = potions.size() - 1;
            int temp = potions.size();   // default if none found
            
            while(start <= end){
                int mid = start + (end - start) / 2;
                long long prod = 1LL * spells[i] * potions[mid];
                
                if(prod >= success){
                    temp = mid;     
                    end = mid - 1;   
                }
                else start = mid + 1;
            }
            result.push_back(potions.size() - temp);
        }
        return result;
    }
};