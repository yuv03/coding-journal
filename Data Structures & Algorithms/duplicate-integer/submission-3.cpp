class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // converting the vector to set
        set<int> st(nums.begin(),nums.end());
        if(nums.size() != st.size()) return true;
        return false;
    }
};