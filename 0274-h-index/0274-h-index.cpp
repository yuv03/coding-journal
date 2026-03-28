class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int max_cit = INT_MIN;
        int n = citations.size();
        int start = 0;
        int end = citations.size()-1;
        bool flag = false;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(citations[mid] >= n-mid){
                flag = true;
                max_cit = max(max_cit, n-mid);
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        if(!flag) return 0;
        return max_cit;
    }
};

// 10,8,5,4,3
// 3,4,5,8,10








