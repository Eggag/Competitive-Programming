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

ll mypow(ll a, ll p){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1) % MOD)) % MOD;
	ll x = mypow(a, p / 2) % MOD;
	return (x * x) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	map<int, pair<int, pi>> m;
	rep(i, n){
		cin >> a[i];
		if(m[a[i]].fi){
			m[a[i]].se.se = i;
		}
		else{
			m[a[i]].fi = 1;
			m[a[i]].se = mp(i, i);
		}
	}
	vi cnt(n + 10, 0);
	for(pair<int, pair<int, pi>> y : m){
		pair<int, pi> x = y.se;
		//so mark each segment	
		//if(x.se.fi == x.se.se) continue;
		cnt[x.se.fi + 1]++;
		cnt[x.se.se + 1]--;
	}
	partial_sum(all(cnt), cnt.begin());
	//rep(i, n) cout << cnt[i];
	//cout << endl;
	int num = 0;
	repn(i, 1, n){
		if(!cnt[i]) num++;
	}
	cout << mypow(2, num) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
