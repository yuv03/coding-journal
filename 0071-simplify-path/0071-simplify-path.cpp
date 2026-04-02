class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans = "";
        string temp="";
        int count = 0;
        bool flag = false;

        for(int i=0; i<path.size(); i++){
            if(path[i]=='.'){
                if(temp.size()>0){
                    temp+= ".";
                }
                else{
                    flag = false;
                    count++;
                }
            }
            else if(path[i]=='/'){
                if(count==2){
                    if(!st.empty()){
                        st.pop();
                    }
                    count=0;
                }
                else if(count > 2){
                    while(count){
                        temp += ".";
                        count--;
                    }
                    st.push(temp);
                    temp="";
                }
                flag = false;
                count=0;

            }
            else{
                if(count>0){
                    while(count){
                        temp += ".";
                        count--;
                    }
                }
                flag = true;
                temp += path[i];
            }

            if(flag==false && temp.size()>0){
                st.push(temp);
                temp="";
            }
        }
        if(temp.size()>0) st.push(temp);
        if(count==2){
            if(!st.empty()){
                st.pop();
            }
        }
        else if(count>2){
            while(count){
                temp += ".";
                count--;
            }
            st.push(temp);
        }
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans=="") return "/";
        return ans;
    }
};