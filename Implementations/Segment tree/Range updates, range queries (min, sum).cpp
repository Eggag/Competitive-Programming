int n;
ll a[mxN], s[4 * mxN], s1[4 * mxN], lazy[4 * mxN];

void build(int id = 1, int l = 0, int r = n){
	if((r - l) < 2){
		s[id] = a[l];
		s1[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build((id << 1) + 1, mid, r);
	s[id] = (s[id << 1] + s[(id << 1) + 1]);
	s1[id] = min(s1[id << 1], s1[(id << 1) + 1]);
}
 
void down(int id, int l, int r){
	if(lazy[id]){
		s[id] += 1LL * lazy[id] * (r - l);
		s1[id] += 1LL * lazy[id];
		if((r - l) > 1){
			lazy[id << 1] += lazy[id];
			lazy[(id << 1) + 1] += lazy[id];
		}
	}
	lazy[id] = 0;
}
 
void increase(int x, int y, ll u, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] += u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id << 1, l, mid);
	increase(x, y, u, (id << 1) + 1, mid, r);
	s[id] = s[id << 1] + s[(id << 1) + 1];
	s1[id] = min(s1[id << 1], s1[(id << 1) + 1]);
}
 
ll sum(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}

ll minQ(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return 1e18;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return min(minQ(x, y, id * 2, l, mid), minQ(x, y, id * 2 + 1, mid, r));
}
