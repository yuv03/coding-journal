class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> ms;
        map<char, int> mt;

        if(s.size() != t.size()) return false;

        for(int i=0; i<s.size(); i++){
            ms[s[i]]++;
            mt[t[i]]++;
        }

        if(ms.size() != mt.size()) return false;
        // Checking the character as well as its frequency
        for(auto it : ms){
            char ch = it.first;
            int freq = it.second;

            if(mt.find(ch) == mt.end()) return false;
            if(mt[ch] != freq) return false;
        }
        return true;
    }
};
