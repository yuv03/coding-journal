class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            if (!st.empty()) {
                while (!st.empty()) {

                    if (st.top() > 0 && asteroids[i] < 0) {
                        if (st.top() > -asteroids[i])
                            break;
                        else if(st.top()== -asteroids[i]){
                            st.pop();
                            break;
                        }
                        else {
                            // cout << "pop 1 " << endl;
                            st.pop();
                            if(st.empty()) {
                                st.push(asteroids[i]);
                                break;
                            }
                        }
                    } else if (st.top() < 0 && asteroids[i] > 0) {
                        st.push(asteroids[i]);
                        break;
                    } else {
                        // cout << "asteroids[i]: " << asteroids[i] << endl;
                        st.push(asteroids[i]);
                        break;
                    }
                }
            } else {
                st.push(asteroids[i]);
                // cout << "out asteroids[i]: " << asteroids[i] << endl;
            }
            // cout << "-------------------" << endl;
            // while (!st.empty()) {
            //     cout << st.top() << " ";
            //     st.pop();
            // }
            // cout << endl;
            // cout << "-------------------" << endl;
        }
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};