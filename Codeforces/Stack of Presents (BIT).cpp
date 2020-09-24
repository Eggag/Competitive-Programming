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
const int MAXN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(MAXN, 0);
	}
	void update(int ind, T delta){
		for(; ind < MAXN; ind += (ind & (-ind))){
			bit[ind] += delta;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind; ind -= (ind & (-ind))){
			sum += bit[ind];
		}
		return sum;
	}
};

void solve(){
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	map<ll, ll> vis, pos, pos1;
	rep(i, n) cin >> a[i], pos[a[i]] = i + 1;
	rep(i, m) cin >> b[i], vis[b[i]] = 1;
	ll ans = 0;
	ll mx = 0;
	BIT<ll> bit;
	rep(i, m){
		if(pos[b[i]] < mx) ans++;
		else{
			ans += 2 * (pos[b[i]] - bit.query(pos[b[i]]) - 1) + 1;
		}
		mx = max(mx, pos[b[i]]);
		bit.update(pos[b[i]], 1);
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
