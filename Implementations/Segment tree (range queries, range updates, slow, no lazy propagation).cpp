int n;
ld a[MAXN], s[4 * MAXN];

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

void update(int x, int y, ld u, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return;
	if(x <= l && r <= y) s[id] = (u * (ld)(r - l));
	if((r - l) < 2) return;
	int mid = (l + r) / 2;
	update(x, y, u, id * 2, l, mid);
	update(x, y, u, id * 2 + 1, mid, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

ld sum(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return (ld)0;
	if(x <= l && r <= y) return (ld)s[id];
	if((r - l) < 2) return (ld)0;
	int mid = (l + r) / 2;
	return (ld)(sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}
