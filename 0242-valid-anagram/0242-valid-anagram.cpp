// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size())
//             return false;

//         vector<int> svec(26, 0);
//         vector<int> tvec(26, 0);

//         for (int i = 0; i < s.size(); i++) {
//             svec[s[i] - 'a']++;
//         }

//         for (int i = 0; i < t.size(); i++) {
//             tvec[t[i] - 'a']++;
//         }

//         int i = 0;
//         while (i < 26) {
//             if (svec[i] != tvec[i])
//                 return false;
//             i++;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> ms;
        map<char, int> mt;
        for(int i=0; i<s.size(); i++){
            ms[s[i]]++;
            mt[t[i]]++;
        }

        map<char, int>::iterator its = ms.begin();
        map<char, int>::iterator itt = mt.begin();

        while(its != ms.end() && itt != mt.end()){
            if(its->first == itt->first){
                if(its->second != itt->second) return false;
            }
            else return false;
            its++;
            itt++;
        }
        if(its != ms.end()) return false;
        if(itt != mt.end()) return false;
        return true;

    }
};





