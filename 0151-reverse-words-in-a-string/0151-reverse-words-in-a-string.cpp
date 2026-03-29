class Solution {
public:
    string reverseWords(string s) {
        
        string temp = "";
        string ans = "";
        vector<string> v;
        
        for(int i=0; i<s.size(); i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                temp.push_back(s[i]);
            }
            else if(s[i]==' '){
                if(!temp.empty()){
                    v.push_back(temp);
                    temp.clear();
                }
            }

            if(i==s.size()-1){
                if(!temp.empty()){
                    v.push_back(temp);
                }
            }
        }

        # // for(int i=0; i<v.size(); i++){
        # //     cout << v[i] << " ";
        # // }
        # // cout << endl;

        for(int i=v.size()-1; i>=0; i--){
            ans += v[i];
            if(i != 0) ans.push_back(' ');
            
        }

        return ans;
        
    }
};