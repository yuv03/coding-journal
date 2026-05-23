class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string temp = "";

        for(auto i : s) {

            if(i == ' ') {
                words.push_back(temp);
                temp = "";
            }
            else {
                temp += i;
            }
        }

        words.push_back(temp);

        if(pattern.size() != words.size())
            return false;

        map<char, string> mp;
        map<string, char> rev;

        for(int i = 0; i < pattern.size(); i++) {

            char ch = pattern[i];
            string word = words[i];

            if(mp.find(ch) != mp.end()) {

                if(mp[ch] != word)
                    return false;
            }
            else {

                if(rev.find(word) != rev.end())
                    return false;

                mp[ch] = word;
                rev[word] = ch;
            }
        }

        return true;
    }
};