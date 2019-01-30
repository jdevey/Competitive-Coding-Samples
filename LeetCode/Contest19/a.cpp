class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool isNeg = num < 0;
        if (isNeg) num = -num;
        string ans;
        while (num) {
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        return isNeg ? '-' + ans : ans;
    }
};
