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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	int n;
	cin >> n;
	vi cnt(10000005, 0);
	vector<pi> p(n);
	rep(i, n){
		cin >> p[i].fi >> p[i].se;
		cnt[p[i].fi]++;
		cnt[p[i].se]--;
	}
	partial_sum(all(cnt), cnt.begin());
	int res = 0;
	rep(i, 10000005) if(cnt[i]) res++;
	vi cnt1(10000005, 0);
	cnt1[0] = (cnt[0] == 1);
	repn(i, 1, 10000005) cnt1[i] = cnt1[i - 1] + (cnt[i] == 1);
	int ans = 0;
	rep(i, n){
		int cur = res - (cnt1[p[i].se - 1] - (p[i].fi ? cnt1[p[i].fi] : 0));
		ans = max(cur, ans);
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
