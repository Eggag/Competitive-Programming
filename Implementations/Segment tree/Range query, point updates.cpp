struct seg{
	ll dat[1 << 20];
	int sz;
	seg(int s){
		sz = s;
		for(int i = 0; i < (1 << 20); i++){
			dat[i] = 1e18;
		}
	}
	void update(int i, int s, int e, int x, ll v){
		if(s == e){
			dat[i] = min(dat[i], v);
			return;
		}
		int m = (s + e) / 2;
		if(x <= m) update(i << 1, s, m, x, v);
		else update(i << 1 | 1, m + 1, e, x, v);
		dat[i] = min(dat[i << 1], dat[i << 1 | 1]);
	}
	void update(int x, ll v){
		update(1, 0, sz, x, v);
	}
	ll query(int i, int s, int e, int x, int y){
		if(e < x || y < s) return 1e18;
		if(x <= s && e <= y) return dat[i];
		int m = (s + e) / 2;
		return min(query(i << 1, s, m, x, y), query(i << 1 | 1, m + 1, e, x, y));
	}
	ll query(int x, int y){
		return query(1, 0, sz, x, y);
	}
};
