class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char, int> countT, window;
        for(char c : t){
            countT[c]++;
        }

        int have = 0; //how many unique characters are currently satisfied in the window
        int need = countT.size(); //number of unique characters required to satisfy

        pair<int, int> res = {-1, -1}; // stores start and end index of best window
        int resLen = INT_MAX; // length of smallest valid window found so far
        int l = 0;

        for(int r = 0; r < s.length(); r++){
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]){
                have++;
            }

            while(have == need) { // try to shrink window
                if((r - l + 1) < resLen){
                    resLen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]){ // check if window became invalid
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);

        
    }
};
