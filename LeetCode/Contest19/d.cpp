typedef long long ll;
class ST {

	int* st;
	int sz;

	public:

	ST(int* a, int _sz) {
		sz = _sz; //NOTE: must not swap this line with the line below!
		st = new int[sz * 4];
		construct(a, 0, sz - 1, 0);
	}

	~ST() {
		delete st;
	}

	int queryUtil(int ql, int qr, int l, int r, int ind) {
		if (l > qr || r < ql) return 0;
		if (l >= ql && r <= qr) return st[ind];
		return queryUtil(ql, qr, l, (l + r) / 2, ind * 2 + 1) +
			queryUtil(ql, qr, (l + r) / 2 + 1, r, ind * 2 + 2);
	}

	int query(int ql, int qr) {
		return queryUtil(ql, qr, 0, sz - 1, 0);
	}

	void updateUtil(int node, int diff, int l, int r, int ind) {
		if (l > node || r < node) return;
		st[ind] += diff;
		if (l == r) return;
		updateUtil(node, diff, l, (l + r) / 2, ind * 2 + 1);
		updateUtil(node, diff, (l + r) / 2 + 1, r, ind * 2 + 2);
	}

	//Change node from current value to value + diff
	//the array 'a' must be the same array that the segment tree was constructed from
	void update(int node) {
		updateUtil(node, 1, 0, sz - 1, 0);
	}

	void construct(int* a, int l, int r, int ind) {
		if (l == r) {
			st[ind] = a[l];
			return;
		}
		construct(a, l, (l + r) / 2, ind * 2 + 1);
		construct(a, (l + r) / 2 + 1, r, ind * 2 + 2);
		st[ind] = st[ind * 2 + 1] + st[ind * 2 + 2];
	}
};
class Solution {
public:
    ll bss(pair <ll, ll> n, vector <pair <ll, ll>>& sst) {
        if (sst[0] == n) return 0;
        ll sz = sst.size();
        ll base = 0;
        for (ll jump = sz / 2; jump; jump >>= 1) while (base + jump < sz && sst[base + jump] < n) base += jump;
        return base + 1;
    }
    ll bs(ll n, vector <ll>& srt) {
        if (n <= srt[0]) return 0;
        ll sz = (ll)srt.size();
        ll base = 0;
        for (ll jump = sz / 2; jump; jump >>= 1) while (base + jump < sz && srt[base + jump] < n) base += jump;
        return base + 1;
    }
    int reversePairs(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        
        int sz = nums.size();
        int a[sz] = {};
        ST st(a, sz);
        
        vector <ll> srt;
        for (int i = 0; i < sz; ++i) srt.push_back(nums[i]);
        sort(srt.begin(), srt.end());
        
        vector <pair <ll, ll>> sst;
        for (int i = 0; i < sz; ++i) sst.push_back({nums[i], i});
        sort(sst.begin(), sst.end());
        
        ll cnt = 0;
        
        for (int i = 0; i < sz; ++i) {
            ll pos2 = bs((ll)nums[i] * 2 + 1, srt);
            cnt += st.query(pos2, sz - 1);
            
            ll pos1 = bss({nums[i], i}, sst);
            st.update(pos1);
        }
        
        return cnt;
    }
};
