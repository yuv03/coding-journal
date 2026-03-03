class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                string temp = "";
                while(st.top()!='['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }
                int counter = stoi(num);
                while(counter){
                    for(int i=0; i<temp.size(); i++){
                        st.push(temp[i]);
                    }
                    counter--;
                }
            }
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }        
        return ans;
    }
};