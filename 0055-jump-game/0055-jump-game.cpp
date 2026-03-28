// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         if(nums.size()==1) return true;
//         bool flag = false;
//         int count = 0;
//         int cons_zeros = 1;
//         bool zeros = false;
//         for(int i=nums.size()-2; i>=0; i--){
//             if(nums[i]==0) {
//                 if(zeros){
//                     cons_zeros++;
//                 } 
//                 else{
//                     zeros = true;
//                     flag = false;
//                 }
//             }
//             else{
//                 zeros = false;
//                 if(!flag){
//                     if(count==0 && cons_zeros>1){
//                         if(nums[i]>cons_zeros){
//                             flag = true;
//                             cons_zeros = 1;
//                         }
//                     }
//                     else{
//                         count++;
//                         if(nums[i]>count){
//                             flag = true;
//                             count = 0;
//                         }
//                     }
//                 }
                
//             }
//         }
        
//     }
// };



class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;

        bool flag = true;
        int count = 0;
        int cons_zeros = 0;
        bool zeros = false;

        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] == 0) {
                if(zeros) {
                    cons_zeros++;
                } else {
                    zeros = true;
                    cons_zeros = 1;
                    count = 0;
                    flag = false;
                }
            }
            else {
                if(zeros) {
                    count++;
                    if(nums[i] > cons_zeros + count - 1) {
                        zeros = false;
                        cons_zeros = 0;
                        count = 0;
                        flag = true;
                    }
                }
            }

            if(i == 0 && zeros) return false;
        }

        return true;
    }
};





// 1,0,3,0,0,2,0,4
//  ,F,F,T,F


// 3,2,1,0,4
//     F F    