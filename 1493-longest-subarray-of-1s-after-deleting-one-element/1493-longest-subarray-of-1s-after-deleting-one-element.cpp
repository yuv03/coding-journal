class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count =0;
        int i=0;
        while (count <1 && i < nums.size()){
            if(nums[i]==0)count++;
            i++;
        }

        if(count ==0) {
            return nums.size()-1;
        }

        int m = 0;
        int n = i;
        int temp = i;
        int maxx = i;


        while(n<nums.size()){
            //cout << "temp: " << temp << endl;
            if(nums[n]==0){
                count++;
                while(count>1){
                    if(nums[m]==0){
                        count--;
                    }
                    m++;
                    temp -=1;
                }
                temp+=1;
            }
            else{
                temp +=1;
            }
            n++;
            maxx = max(maxx, temp);
        }
        return maxx-1;


        
    }
};