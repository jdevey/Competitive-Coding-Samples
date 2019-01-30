class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int sz = nums.size(), sm = 0, mx = 0;
        set <pair <int, int>> s;
        s.insert({0, -1});
        for (int i = 0; i < sz; ++i) {
            sm += nums[i] ? 1 : -1;
            auto it = s.lower_bound({sm, -1});
            if (it != s.end() && it->first == sm) mx = max(mx, i - it->second);
            s.insert({sm, i});
        }
        return mx;
    }
};
