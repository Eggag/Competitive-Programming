ll lcm(ll a, ll b){
	return ((a * b) / gcd(a, b));
}

struct frac{
	ll a, b;
	void pr(){
		ll g = gcd(a, b);
		a /= g;
		b /= g;
	}
	bool operator == (const frac &p) const{
		return (ll)(a * p.b) == (ll)(b * p.a);
	}
	bool operator < (const frac &p) const{
		return (ll)(a * p.b) < (ll)(b * p.a);
	}
};

frac add(frac q, frac p){
	ll l = lcm(q.b, p.b);
	q.a *= (l / q.b);
	p.a *= (l / p.b);
	frac now = (frac){q.a + p.a, l};
	now.pr();
	return (frac)now;
}

frac mul(frac q, frac p){
	frac ret = (frac){q.a * p.a, q.b * p.b};
	ret.pr();
	return ret;
}
