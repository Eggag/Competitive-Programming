ll mysqrt(ll x){
	ll l = 0, r = 1e10;
	while ((r - l) > 1){
		ll m = (l + r) / 2;
		if((m * (ll)(m)) <= x) l = m;
		else r = m;
	}
	return l;
}
