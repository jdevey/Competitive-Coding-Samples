class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        set <int> si;
        for (auto x : G) si.insert(x);
        int cnt = 0;
        bool ic = false;
        while (head != NULL) {
            if (ic) {if (si.find(head->val) == si.end()) ic = false;}
            else if (si.find(head->val) != si.end()) {++cnt; ic = true;}
            head = head->next;
        }
        return cnt;
    }
};
