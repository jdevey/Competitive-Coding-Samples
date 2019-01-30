class Solution {
public:
    bool isCap(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool isFirst(string s) {
        if (!isCap(s[0])) return false;
        for (int i = 1; i < s.size(); ++i) if (isCap(s[i])) return false;
        return true;
    }
    bool isNotCaps(string s) {
        for (auto x : s) if (isCap(x)) return false;
        return true;
    }
    bool isAllCaps(string s) {
        for (auto x : s) if (!isCap(x)) return false;
        return true;
    }
    bool detectCapitalUse(string word) {
        if (word.size() == 1) {
            return true;
        }
        if (isAllCaps(word) || isNotCaps(word) || isFirst(word)) return true;
        return false;
    }
};
