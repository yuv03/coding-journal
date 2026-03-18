class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1; i<strs.size(); i++){
            if(strs[i].size()==0){
                ans = "";
                break;
            }
            string temp = "";
            int j = 0;
            int k =0;
            while(j<ans.size() && k<strs[i].size()){
                if(ans[j]==strs[i][k]){
                    temp += ans[j];
                    j++;
                    k++;
                    if(j==ans.size() || k==strs[i].size()) ans = temp;
                }
                else{
                    ans = temp;
                    break;
                }
            }
        }
        return ans; 
    }
};