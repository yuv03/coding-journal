class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        set<vector<int>> st;
        vector<vector<int>> ans;

        while(i<nums.size()-2){
            int j=i+1;
            int k=nums.size()-1;
            int target = -nums[i];

            // vector<int> temp;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } 
                else if(nums[j]+nums[k]>target) k--;
                else j++;
            }
            i++;
        }
        ans= vector<vector<int>>(st.begin(), st.end());
        return ans;
    }
};