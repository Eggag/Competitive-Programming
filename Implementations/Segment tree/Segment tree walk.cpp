struct seg{
	int dat[1 << 21];
	int sz;
	seg(int s){
		sz = s;
		for(int i = 0; i < (1 << 21); i++){
			dat[i] = 0;
		}
	}
	void update(int i, int s, int e, int x, int v){
		if(s == e){
			dat[i] = v;
			return;
		}
		int m = (s + e) / 2;
		if(x <= m) update(i << 1, s, m, x, v);
		else update(i << 1 | 1, m + 1, e, x, v);
		dat[i] = gcd(dat[i << 1], dat[i << 1 | 1]);
	}
	void update(int x, int v){
		update(1, 0, sz, x, v);
	}
	int query(int i, int s, int e, int x, int y, int val){
		if(e < x || y < s) return -1;
		if(x <= s && e <= y){
			if(dat[i] % val == 0) return -1;
			while(s != e){
				int mid = (s + (e - s) / 2);
				if(dat[2 * i] % val != 0){
					i = 2 * i;
					e = mid;
				}
				else{
					i = 2 * i + 1;
					s = mid + 1;
				}
			}
			return s;
		}
		int m = (s + e) / 2;
		int uwu = query(i << 1, s, m, x, y, val);
		if(uwu != -1) return uwu;
		return query(i << 1 | 1, m + 1, e, x, y, val);
	}
	int query(int x, int y, int val){
		return query(1, 0, sz, x, y, val);
	}
	int ask(int i, int s, int e, int x, int y){
		if(e < x || y < s) return 0;
		if(x <= s && e <= y) return dat[i];
		int m = (s + e) / 2;
		return gcd(ask(i << 1, s, m, x, y), ask(i << 1 | 1, m + 1, e, x, y));
	}
	int ask(int x, int y){
		if(y < x) return 0;
		return ask(1, 0, sz, x, y);
	}
};
