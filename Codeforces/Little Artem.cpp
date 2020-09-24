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
	int n, m;
	cin >> n >> m;
	char ans[n][m];
	int cntW = 0, cntB = 0;
	rep(i, n){
		rep(j, m){
			if((i + j) & 1) ans[i][j] = 'W', cntW++;
			else ans[i][j] = 'B', cntB++;
		}
	}
	if(cntB == cntW){
		rep(i, n) rep(j, m) if(ans[i][j] == 'W'){
			int b = 0;
			if(i && ans[i - 1][j] == 'B') b++;
			if(j && ans[i][j - 1] == 'B') b++;
			if(i < (n - 1) && ans[i + 1][j] == 'B') b++;
			if(j < (m - 1) && ans[i][j + 1] == 'B') b++;
			if(b){
				ans[i][j] = 'B';
				goto h;
			}
		}
	}
h:;
	rep(i, n){
		rep(j, m) cout << ans[i][j];
		cout << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
