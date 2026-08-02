class Solution {
public:
    bool closeStrings(string word1, string word2) {

        map<char, int> mp1;
        map<char, int> mp2;
        if(word1.size() != word2.size()) return false;

        for(int i=0; i<word1.size(); i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }

        map<char, int>::iterator it1 = mp1.begin();
        map<char, int>:: iterator it2 = mp2.begin();

        vector<int> freq1;
        vector<int> freq2;

        while(it1 != mp1.end() && it2 != mp2.end()){
            if(it1->first != it2->first) return false;
            freq1.push_back(it1->second);
            freq2.push_back(it2->second);
            it1++;
            it2++;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        if(freq1 != freq2) return false;
        return true; 
    }
};

