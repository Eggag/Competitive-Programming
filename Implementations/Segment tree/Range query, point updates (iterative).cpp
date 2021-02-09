struct seg{
	int sz;
	int mn[1 << 19], mx[1 << 19];
	void update(int p, int val){
		for(mx[p + sz] = val, mn[p += sz] = val; p > 1; p >>= 1){
			mx[p >> 1] = max(mx[p], mx[p ^ 1]);
			mn[p >> 1] = min(mn[p], mn[p ^ 1]);
		}
	}
	int queryMax(int l, int r){
		r++;
		int res = -1e9;
		for(l += sz, r += sz; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = max(res, mx[l++]);
			if(r & 1) res = max(res, mx[--r]);
		}
		return res;
	}
	int queryMin(int l, int r){
		r++;
		int res = 1e9;
		for(l += sz, r += sz; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = min(res, mn[l++]);
			if(r & 1) res = min(res, mn[--r]);
		}
		return res;
	}
};
