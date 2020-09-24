/*
ID: egor_ga1
PROG: frac1
LANG: C++11
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int cnt[200][200];

int lcm(int a, int b){
	return ((a * b) / gcd(a, b));
}

struct frac{
	int a, b;
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
	int l = lcm(q.b, p.b);
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


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	int n;
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	vector<frac> p;
	p.pb((frac){0, 1});
	repn(i, 1, n + 1) repn(j, i, n + 1){
		frac fr = (frac){i, j};
		fr.pr();
		if(!cnt[fr.a][fr.b]){
			cnt[fr.a][fr.b]++;
			p.pb(fr);
		}
	}
	sort(all(p));
	rep(i, p.size()){
		cout << p[i].a << "/" << p[i].b << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
