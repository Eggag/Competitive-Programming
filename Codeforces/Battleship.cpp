#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

string s[105];
int cnt[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	rep(i, n) cin >> s[i];
	rep(i, 105) rep(j, 105) cnt[i][j] = 0;
	//rows
	rep(i, n){
		rep(j, n - k + 1){
			bool f = 1;
			repn(l, j, j + k){
				if(s[i][l] == '#') f = 0;
			}
			if(f){
				repn(l, j, j + k) cnt[i][l]++;
			}
		}
	}
	//colums
	rep(j, n){
		rep(i, n - k + 1){
			bool f = 1;
			repn(l, i, i + k){
				if(s[l][j] == '#') f = 0;
			}
			if(f){
				repn(l, i, i + k) cnt[l][j]++;
			}
		}
	}
	int mx = 0;
	pi ans = {1, 1};
	rep(i, n) rep(j, n){
		if(cnt[i][j] > mx){
			mx = cnt[i][j];
			ans.fi = i + 1, ans.se = j + 1;
		}
	}
	cout << ans.fi << " " << ans.se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
