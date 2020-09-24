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

int dp[15][15][15][15];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	rep(i, 15) rep(j, 15) rep(k, 15) rep(l, 15) dp[i][j][k][l] = 1e9;
	rep(i, 10) rep(j, 10) rep(st, 10) rep(ci, 10) rep(cj, 10) if(ci + cj){
		int to = (st + (i * ci) + (j * cj)) % 10;
		dp[i][j][st][to] = min(dp[i][j][st][to], ci + cj);
	}
	rep(i, 10){
		rep(j, 10){
			int cnt = 0;
			int prev = 0;
			repn(k, 1, s.size()){
				int ln = dp[i][j][prev][(s[k] - '0')] - 1;
				if(ln == (1e9 - 1)){
					cnt = -1;
					break;
				}
				prev = (s[k] - '0');
				cnt += ln;
			}
			cout << cnt << " ";
		}
		cout << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
