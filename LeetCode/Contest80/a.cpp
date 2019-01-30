class Solution {
public:
    bool isLetter(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
    
    char makeLower(char c) {
        if (c <= 'Z') return c + 32;
        else return c;
    }
    
    string mwl(string s) {
        string ret;
        for (auto x : s) ret += makeLower(x);
        return ret;
    }
    
    string mostCommonWord(string par, vector<string>& banned) {
        set <string> b;
        for (auto x : banned) b.insert(x);
        map <string, int> m;
        string imm;
        for (int i = 0; i < par.size(); ++i) {
            if (isLetter(par[i])) imm += par[i];
            else {
                if (!imm.empty()) {
                    string n = mwl(imm);
                    if (b.find(n) == b.end()) ++m[n];
                    imm.clear();
                }
            }
        }
        if (!imm.empty()) {
            string n = mwl(imm);
            if (b.find(n) == b.end()) ++m[n];
        }
        int mx = 0;
        string mxString;
        for (auto x : m) {
            if (x.second > mx) {
                mx = max(mx, x.second);
                mxString = x.first;
            }
        }
        return mxString;
    }
};
