class Solution {
public:
    void printt(int ind, vector<vector<int>>& subs, vector<int>& temp, vector<int> nums){
        if(ind == nums.size()){
            subs.push_back(temp);
            return ;
        }
        temp.push_back(nums[ind]);
        printt(ind+1, subs, temp, nums);
        temp.pop_back();
        printt(ind+1, subs, temp, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> temp;
        printt(0, subs, temp, nums);
        return subs;
    }
};