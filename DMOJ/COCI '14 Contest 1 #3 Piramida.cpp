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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n;
string s;
vi g[30];

ll lz(int ch, int la){
	if(!g[ch].size()) return 0LL;
	if(g[ch][0] > la) return 0LL;
	if(g[ch][g[ch].size() - 1] <= la) return (ll)(g[ch].size());
	ll nm = ub(all(g[ch]), la) - g[ch].begin();
	return nm;
}

void solve(){
	ll a;
	char c;
	cin >> a >> c;
	ll k = s.size();
	ll one = a, two = a - 1;
	if(one % 2 == 0) one /= 2;
	else two /= 2;
	ll num = (one % k * (two % k)) % k;
	num = k - num;
	if(a < num && num != k){
		num = k - num;
		cout << lz(c - 'A', num - 1 + a) - lz(c - 'A', num - 1) << endl;
		return;
	}
	ll ans = 0LL;
	if(num != k){
		ans = lz(c - 'A', k - 1) - ((k - num - 1) >= 0 ? lz(c - 'A', k - num - 1) : 0);
	}
	ll tot = a;
	if(num != k) tot -= num;
	ans += (ll)(lz(c - 'A', k - 1) * (ll)(tot / k));
	tot = tot % k;
	if(tot) ans += (ll)(lz(c - 'A', tot - 1));
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	cin >> s;
	rep(i, s.size()) g[s[i] - 'A'].pb(i);
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
