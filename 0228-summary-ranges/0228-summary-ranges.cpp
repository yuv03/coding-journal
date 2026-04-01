class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0) return ans;
        int start = 0;
        int end = 0;
        int count = 0;
        string str ="";

        while(end<nums.size()){
            long long diff = (long long)nums[end]-nums[start];
            if(diff==count){
                end++;
                count++;
            }
            else{
                if(count==1){
                    str += to_string(nums[start]);
                    ans.push_back(str);
                    str="";
                    start = end;
                    count = 0;
                }
                else{
                    str += to_string(nums[start]);
                    str += "->";
                    str += to_string(nums[end-1]);
                    ans.push_back(str);
                    start = end;
                    str="";
                    count=0; 
                }
            }
        }
        if(count==1){
            str += to_string(nums[start]);
            ans.push_back(str);
        }
        else{
            str += to_string(nums[start]);
            str += "->";
            str += to_string(nums[end-1]);
            ans.push_back(str);
        }
        return ans;
    } 
};