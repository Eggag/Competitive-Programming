int n;
ld a[MAXN], s[4 * MAXN], lazy[4 * MAXN];

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

void update(int id, int l, int r, ld x){
	lazy[id] += x;
	if(x) s[id] = (r - l) * x;
}

void shift(int id, int l, int r){
	int mid = (l + r) / 2;
	update(id * 2, l, mid, lazy[id]);
	update(id * 2 + 1, mid, r, lazy[id]);
	lazy[id] = 0;
}

void increase(int x, int y, ld u, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		update(id, l, r, u);
		return;
	}
	shift(id, l, r);
	int mid = (l + r) / 2;
	increase(x, y, u, id * 2, l, mid);
	increase(x, y, u, id * 2 + 1, mid, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

ld sum(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id];
	shift(id, l, r);
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}
