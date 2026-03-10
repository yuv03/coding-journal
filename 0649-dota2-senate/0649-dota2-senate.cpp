class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad;
        queue<int> dir;
        int n = senate.size();
        for(int i=0; i<senate.size(); i++){
            (senate[i]=='R') ? rad.push(i) : dir.push(i);
        }

        while(!rad.empty() && !dir.empty()){
            if(rad.front() < dir.front()){
                rad.push(++n);
            }
            else{
                dir.push(++n);
            }
            rad.pop();
            dir.pop();
        }
        return (rad.empty()) ? "Dire" : "Radiant"; 
    } 
};