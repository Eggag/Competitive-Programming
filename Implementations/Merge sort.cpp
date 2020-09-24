vi merge_sort(vi a){
	if(a.size() == 1) return a;
	vi ret;
	int n = a.size();
	vi lf, rt;
	rep(i, n / 2) lf.pb(a[i]);
	repn(i, n / 2, n) rt.pb(a[i]);
	vi p1 = merge_sort(lf), p2 = merge_sort(rt);
	int x = 0, y = 0;
	rep(i, n){
		if(x == p1.size()) ret.pb(p2[y]), y++;
		else if(y == p2.size()) ret.pb(p1[x]), x++;
		else{
			if(p1[x] < p2[y]) ret.pb(p1[x]), x++;
			else ret.pb(p2[y]), y++;
		}
	}
	return ret;
}
