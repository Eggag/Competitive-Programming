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

vector<ll> cnt[4];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, w;
	cin >> n >> w;
	vector<ll> a(n), b(n);
	cnt[0].pb(0);
	cnt[1].pb(0);
	cnt[2].pb(0);
	cnt[3].pb(0);
	rep(i, n){
		cin >> a[i] >> b[i];
		cnt[a[i] - a[0]].pb(b[i]);
	}
	sort(cnt[0].begin() + 1, cnt[0].end());
	sort(cnt[1].begin() + 1, cnt[1].end());
	sort(cnt[2].begin() + 1, cnt[2].end());
	sort(cnt[3].begin() + 1, cnt[3].end());
	reverse(cnt[0].begin() + 1, cnt[0].end());
	reverse(cnt[1].begin() + 1, cnt[1].end());
	reverse(cnt[2].begin() + 1, cnt[2].end());
	reverse(cnt[3].begin() + 1, cnt[3].end());
	repn(i, 1, cnt[0].size()) cnt[0][i] += cnt[0][i - 1];
	repn(i, 1, cnt[1].size()) cnt[1][i] += cnt[1][i - 1];
	repn(i, 1, cnt[2].size()) cnt[2][i] += cnt[2][i - 1];
	repn(i, 1, cnt[3].size()) cnt[3][i] += cnt[3][i - 1];
	ll ans = 0;
	rep(i, cnt[0].size()) rep(j, cnt[1].size()) rep(k, cnt[2].size()) rep(l, cnt[3].size()){
		if(((i * a[0]) + (j * (a[0] + 1)) + (k * (a[0] + 2)) + (l * (a[0] + 3))) <= w){
			ll cur = cnt[0][i] + cnt[1][j] + cnt[2][k] + cnt[3][l];
			ans = max(ans, cur);
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
