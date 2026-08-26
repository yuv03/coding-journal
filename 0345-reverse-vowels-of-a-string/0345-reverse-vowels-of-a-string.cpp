class Solution {
public:
    string reverseVowels(string s) {
        int start = 0;
        int end = s.size()-1;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u',
                       'A', 'E', 'I', 'O', 'U'};

        while(start <= end){
            if(find(vowels.begin(), vowels.end(), s[start]) != vowels.end() && find(vowels.begin(), vowels.end(), s[end]) != vowels.end()){
                swap(s[start], s[end]);
                start++;
                end--;
            }
            else if(find(vowels.begin(), vowels.end(), s[start]) != vowels.end() && find(vowels.begin(), vowels.end(), s[end]) == vowels.end()){
                end--;
            }
            else{
                start++;
            }
        }
        return s;
    }
};