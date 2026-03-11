class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size());

        for(int i=temperatures.size()-1; i>=0; i--){
            while(!st.empty() && st.top().first <= temperatures[i]) st.pop();

            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i] = st.top().second - i;
            }
            pair<int, int> p = make_pair(temperatures[i],i);
            st.push(p);
        }
        return ans;
    }
};