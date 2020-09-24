#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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

ll solve(ll p, ll f, ll cntS, ll cntW, ll s, ll w){
	ll mx = 0;
	ll p1 = p, f1 = f;
	rep(i, cntS + 1){
		p = p1, f = f1;
		ll cur = s * i;
		if(cur > p) break;
		ll rem = p - cur;
		ll nw = i;
		ll j;
		if(w * cntW > rem){
			j = rem / w;
			nw += j;
		}
		else nw += cntW, j = cntW;
		//now for the other one we first take as many
		ll ps = f / s;
		ll lft = min(ps, cntS - i);
		f -= lft * s;
		nw += lft;
		ll ps1 = f / w;
		ll lft1 = min(ps1, cntW - j);
		nw += lft1;
		mx = max(mx, nw);
	}
	rep(i, cntW + 1){
		p = p1, f = f1;
		ll cur = w * i;
		if(cur > p) break;
		ll rem = p - cur;
		ll nw = i;
		ll j;
		if(s * cntS > rem){
			j = rem / s;
			nw += j;
		}
		else nw += cntS, j = cntS;
		//now for the other one we first take as many
		ll ps = f / w;
		ll lft = min(ps, cntW - i);
		f -= lft * w;
		nw += lft;
		ll ps1 = f / s;
		ll lft1 = min(ps1, cntS - j);
		nw += lft1;
		mx = max(mx, nw);
	}
	return mx;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		ll p, f;
		cin >> p >> f;
		ll cntS, cntW;
		cin >> cntS >> cntW;
		ll s, w;
		cin >> s >> w;
		ll res = 0LL;
		if(w > s) swap(s, w), swap(cntS, cntW);
		res = max(res, solve(p, f, cntS, cntW, s, w));
		res = max(res, solve(f, p, cntS, cntW, s, w));
		cout << res << endl;
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
