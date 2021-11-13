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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if(n % k != 0){
		cout << -1 << '\n';
		return;
	}
	if(n == 1){
		cout << s << '\n';
		return;
	}
	vi cnt(26, 0), nmb(n, 0);
	int mx = -1;
	rep(i, n){
		int req = 0;
		int cr = -1, av = -1;
		rep(j, 26){
			if(cnt[j] % k != 0){
				req += k - (cnt[j] % k);
				cr = max(cr, j);
			}
			else av = max(av, j);
		}
		if(i + req <= n){
			int f = ((i + req) < n && av > (s[i] - 'a'));
			if(cr > (s[i] - 'a') || f) mx = max(mx, i), nmb[i] = (i + req);
		}
		cnt[s[i] - 'a']++;
	}
	int nm = 0;
	rep(i, 26) if(cnt[i] % k != 0) nm = 1;
	if(!nm){
		cout << s << '\n';
		return;
	}
	rep(i, 26) cnt[i] = 0;
	int act = 1e9, nxt = 1e9;
	vector<char> ans;
	rep(i, mx) cnt[s[i] - 'a']++, ans.pb(s[i]);
	rep(i, 26){
		if(cnt[i] % k == 0){
			if(i > (s[mx] - 'a')) nxt = min(nxt, i);
		}
		else if(i > (s[mx] - 'a')){
			act = min(act, i);
		}
	}
	if(act < nxt || nmb[mx] == n){
		assert(act != 1e9);
		ans.pb((char)('a' + act));
		cnt[act]++;
		vector<char> ans1;
		rep(i, 26){
			if(cnt[i] % k != 0){
				rep(j, k - (cnt[i] % k)){
					ans1.pb((char)('a' + i));
				}
			}
		}
		sort(all(ans1));
		while((int)(ans1.size() + ans.size()) < n) ans.pb('a');
		string ret = "";
		for(char x : ans) ret += x;
		for(char x : ans1) ret += x;
		vi cnt1(26, 0);
		rep(i, n) cnt1[ret[i] - 'a']++;
		rep(i, 26) assert(cnt1[i] % k == 0);
		cout << ret << '\n';
	}
	else{
		assert(nxt != 1e9);
		cnt[nxt]++;
		ans.pb((char)('a' + nxt));
		vector<char> ans1;
		rep(i, 26){
			if(cnt[i] % k != 0){
				rep(j, k - (cnt[i] % k)){
					ans1.pb((char)('a' + i));
				}
			}
		}
		sort(all(ans1));
		while((int)(ans1.size() + ans.size()) < n) ans.pb('a');
		string ret = "";
		for(char x : ans) ret += x;
		for(char x : ans1) ret += x;
		vi cnt1(26, 0);
		rep(i, n) cnt1[ret[i] - 'a']++;
		rep(i, 26) assert(cnt1[i] % k == 0);
		cout << ret << '\n';
	}
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
