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
const int mxN = 55;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

char ans[mxN][mxN];

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i, n) rep(j, n) ans[i][j] = '.';
	rep(i, n) ans[i][i] = 'X';
	rep(i, n) if(s[i] == '1'){
		rep(j, n) if(ans[i][j] == '.') ans[i][j] = ans[j][i] = '=';
	}
	rep(i, n) if(s[i] == '2'){
		int f = 0;
		rep(j, n) if(ans[i][j] == '.' && ans[j][i] == '.' && s[j] == '2'){
			int cnt = 0, f1 = 0;
			rep(k, n){
				if(ans[j][k] == '.') cnt++;
				if(ans[j][k] == '+') f1 = 1;
			}
			if(!f1 && cnt <= 1) continue;
			ans[i][j] = '+';
			ans[j][i] = '-';
			f = 1;
			break;
		}
		if(!f){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	rep(i, n){
		rep(j, n){
			if(ans[i][j] == '.') ans[i][j] = '=';
			cout << ans[i][j];
		}
		cout << '\n';
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
