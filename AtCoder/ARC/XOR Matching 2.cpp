#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), b(n);
	unordered_map<int, int> cnt;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i], cnt[b[i]]++;
	vi pos;
	rep(i, n) pos.pb(a[0] ^ b[i]);
	vi ans;
	rep(i, pos.size()){
		int f = 1;
		rep(j, n){
			if(!cnt[a[j] ^ pos[i]]){
				f = 0;
				break;
			}
			else cnt[a[j] ^ pos[i]]--;
		}
		if(f) ans.pb(pos[i]);
		rep(j, n) cnt[b[j]]++;
	}
	sort(all(ans));
	vi ans1;
	if(ans.size()) ans1.pb(ans[0]);
	repn(i, 1, ans.size()) if(ans[i] != ans[i - 1]) ans1.pb(ans[i]);
	cout << (int)(ans1.size()) << '\n';
	for(int x : ans1) cout << x << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
