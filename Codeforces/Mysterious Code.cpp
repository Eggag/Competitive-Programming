#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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

int dp[55][55];
int a[2][55][30];
int mx[55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string c, s, t;
	cin >> c >> s >> t;
	int n = c.size(), m = s.size(), p = t.size();
	//0
	rep(i, m) rep(j, 26){
		string cr = s.substr(0, i);
		cr += (char)('a' + j);
		int sz = cr.size();
		//a[0][i][j]
		rep(k, sz) if(sz - k < m){
			string nw = cr.substr(k, sz - k);
			if(nw == s.substr(0, sz - k)){
				a[0][i][j] = sz - k;
				break;
			}
		}
	}
	string cr = s.substr(0, m);
	int sz = cr.size();
	repn(k, 1, sz){
		string nw = cr.substr(k, sz - k);
		if(nw == s.substr(0, sz - k)){
			a[0][54][0] = sz - k;
			break;
		}
	}
	//1
	rep(i, p) rep(j, 26){
		string cr = t.substr(0, i);
		cr += (char)('a' + j);
		int sz = cr.size();
		//a[1][i][j]
		rep(k, sz) if(sz - k < p){
			string nw = cr.substr(k, sz - k);
			if(nw == t.substr(0, sz - k)){
				a[1][i][j] = sz - k;
				break;
			}
		}
	}
	cr = t.substr(0, p);
	sz = cr.size();
	repn(k, 1, sz){
		string nw = cr.substr(k, sz - k);
		if(nw == t.substr(0, sz - k)){
			a[1][54][0] = sz - k;
			break;
		}
	}
	rep(i, 55) rep(j, 55) dp[i][j] = mx[i][j] = -1e9;
	mx[0][0] = 0;
	repn(i, 1, n + 1){
		char cur = c[i - 1];
		for(int j = 0; j < 26; j++){
			char ch = (char)('a' + j);
			if(cur != '*' && ch != cur) continue;
			rep(k, m) rep(l, p){
				int k1 = k, l1 = l, f = 0;
				if(s[k1] == ch){
					k1++;
					if(k1 == m) k1 = a[0][54][0], f++;
				}
				else k1 = a[0][k1][j];
				if(t[l1] == ch){
					l1++;
					if(l1 == p) l1 = a[1][54][0], f--;
				}
				else l1 = a[1][l1][j];
				dp[k1][l1] = max(mx[k][l] + f, dp[k1][l1]);
			}
		}
		rep(j, 55) rep(k, 55) mx[j][k] = dp[j][k], dp[j][k] = -1e9;
	}
	int ans = -1e9;
	rep(j, m) rep(k, p) ans = max(ans, mx[j][k]);
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
