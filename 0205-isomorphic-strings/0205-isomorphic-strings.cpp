class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, char> revmp;
        int i=0;
        while(i<s.size()){

            auto it = mp.find(s[i]);
            if(it!=mp.end()){
                if(it->second != t[i]) return false;
            }
            else{
                mp[s[i]] = t[i];
            }

            auto revit = revmp.find(t[i]);
            if(revit != revmp.end()){
                if(revit->second != s[i]) return false;
            }
            else{
                revmp[t[i]] = s[i];
            }
            i++;
            
        }
        return true;
    }
};