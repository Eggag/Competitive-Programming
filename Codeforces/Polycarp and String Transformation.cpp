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

void solve(){
	string t;
	cin >> t;
	string ans = "", ans1 = "";
	vi vis(30, 0);
	int n = (int)(t.size());
	for(int i = n - 1; i >= 0; i--){
		if(!vis[t[i] - 'a']) ans1 += t[i];
		vis[t[i] - 'a'] = 1;
	}
	reverse(all(ans1));
	vi cnt(30, 0), req(30, 0);
	rep(i, n) cnt[t[i] - 'a']++;
	rep(i, ans1.size()){
		int nm = cnt[ans1[i] - 'a'];
		if(nm % (i + 1) != 0){
			cout << -1 << '\n';
			return;
		}
		req[ans1[i] - 'a'] = nm / (i + 1);
	}
	rep(i, n){
		if(!req[t[i] - 'a']) break;
		req[t[i] - 'a']--;
		ans += t[i];
	}
	string chk = "", ans2 = ans;
	rep(i, ans1.size()){
		if(i){
			string nw = "";
			rep(j, ans2.size()) if(ans2[j] != ans1[i - 1]) nw += ans2[j];
			ans2 = nw;
		}
		chk += ans2;
	}
	if(chk != t) cout << -1 << '\n';
	else cout << ans << ' ' << ans1 << '\n';
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
