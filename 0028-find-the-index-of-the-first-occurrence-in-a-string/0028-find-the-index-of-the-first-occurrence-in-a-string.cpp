class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.empty()) return 0;

        int n = haystack.size();
        int m = needle.size();

        int startIndex = INT_MAX;
        int flag = 0;

        for(int i = 0; i <= n - m; i++){
            int j = 0;

            while(j < m && haystack[i + j] == needle[j]){
                j++;
            }

            if(j == m){
                startIndex = min(startIndex, i);
                flag = 1;
                break; 
            }
        }

        return flag ? startIndex : -1;
    }
};