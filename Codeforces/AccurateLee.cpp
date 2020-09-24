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

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	rep(i, n) if(s[i] == '1') cnt++;
	if(!cnt || cnt == n){
		cout << s << endl;
		return;
	}
	string ans = "";
	rep(i, n){
		if(s[i] == '1'){
			ans = s.substr(0, i);
			break;
		}
	}
	int f = 0;
	int m = 0;
	int f1 = 0;
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == '0' && !f) m = i, f = 1;
		if(s[i] == '1' && f){
			string cur = s.substr(m, n - m);
			ans += cur;
			f1 = 1;
			cnt++;
			break;
		}
	}
	cout << ans;
	if(!f1){
		rep(i, cnt) cout << '1';
		cout << endl;
	}
	else cout << endl;
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
