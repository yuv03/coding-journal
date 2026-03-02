class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        while (i < chars.size() && j < chars.size()) {
            if (chars[i] == chars[j]) {
                j++;
            } else {
                string s = to_string(j - i);
                if (j - i != 1) {
                    int st = i + 1;
                    for (int k = 0; k < s.size(); k++) {
                        chars[st] = s[k];
                        st++;
                    }
                    chars.erase(chars.begin() + st, chars.begin() + j);
                    j = i + s.size() + 1;
                }
                i = j;
            }
        }
        if (j - i != 1) {
            int st = i + 1;
            string s = to_string(j - i);
            for (int k = 0; k < s.size(); k++) {
                chars[st] = s[k];
                st++;
            }
            chars.erase(chars.begin() + st, chars.begin() + j);
        }
        return chars.size();
    }
};