int n;
ll a[MAXN], s[4 * MAXN], lazy[4 * MAXN], b[MAXN], marked[4 * MAXN];

void build(int id = 1, int l = 0, int r = n){
	if((r - l) < 2){
		s[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s[id] = (s[id * 2] + s[id * 2 + 1]);
}

void down(int id, int l, int r){
	if(lazy[id]){
		s[id] = 1LL * lazy[id] * (r - l);
		if((r - l) > 1){
			lazy[2 * id] = lazy[id];
			lazy[2 * id + 1] = lazy[id];
		}
	}
	lazy[id] = 0;
}

void increase(int x, int y, ll u, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] = u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id * 2, l, mid);
	increase(x, y, u, id * 2 + 1, mid, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

ll sum(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}
