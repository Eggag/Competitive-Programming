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
const int MOD = 998244353;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll fact[300005];

bool cmp(pi a, pi b){
	return a.se < b.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	fact[0] = 1;
	for(ll i = 1; i < 300005; i++){
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
	}
	sort(all(p));
	//left half
	int cur = 1;
	ll ans = 1LL;
	repn(i, 1, n){
		if(p[i].fi != p[i - 1].fi){
			(ans *= fact[cur]) %= MOD;
			cur = 1;
		}
		else cur++;
	}
	(ans *= fact[cur]) %= MOD;
	//right half
	sort(all(p), cmp);
	cur = 1;
	ll ans1 = 1LL;
	repn(i, 1, n){
		if(p[i].se != p[i - 1].se){
			(ans1 *= fact[cur]) %= MOD;
			cur = 1;
		}
		else cur++;
	}
	(ans1 *= fact[cur]) %= MOD;
	ll add = 0LL;
	sort(all(p));
	int f = 1;
	repn(i, 1, n) if(p[i].se < p[i - 1].se){
		f = 0;
		break;
	}
	if(f){
		add = 1LL;
		int cur = 0;
		while(cur < n){
			int l = 0, r = n - cur - 1;
			while(l < r){
				int mid = (l + r + 1) / 2;
				if(p[cur + mid].fi == p[cur].fi && p[cur + mid].se == p[cur].se) l = mid;
				else r = mid - 1;
			}
			(add *= fact[l + 1]) %= MOD;
			cur += l + 1;
		}
	}
	cout << (((fact[n] + 2 * MOD - ((ans + ans1) % MOD)) % MOD) + add) % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
