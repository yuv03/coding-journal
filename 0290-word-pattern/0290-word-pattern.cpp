class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        stringstream ss(s);
        string word;
        int i = 0;

        while (ss >> word) {
            if (i >= pattern.size()) return false;

            char c = pattern[i];

            if (mp.count(c)) {
                if (mp[c] != word) return false;
            } else {
                if (rev.count(word)) return false;
                mp[c] = word;
                rev[word] = c;
            }
            i++;
        }

        return i == pattern.size();
    }
};