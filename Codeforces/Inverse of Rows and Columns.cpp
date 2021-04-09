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
const int mxN = 205;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
int g[mxN][mxN];
int f[2][mxN], nf[2][mxN];
string s[2];

void solve(int x, int y){
	if(!x){
		rep(i, 2){
			string a = "", b = "";
			rep(j, m){
				char ch = '1';
				if(g[0][j] && i) ch = '0';
				if(!g[0][j] && !i) ch = '0';
				if(j >= y){
					if(ch == '1') ch = '0';
					else ch = '1';
				}
				a += ch;
			}
			b += (char)('0' + i);
			int ans = 1;
			repn(k, 1, n){
				int tot = 0;
				rep(j, m){
					if(a[j] == '1') tot += 1 - g[k][j];
					else tot += g[k][j];
				}
				if(!tot) b += '1';
				else if(tot == m) b += '0';
				else{
					ans = 0;
					break;
				}
			}
			if(ans){
				cout << "YES\n";
				cout << b << '\n';
				cout << a << '\n';
				exit(0);
			}
		}
	}
	rep(ind, 2){
		int ans = 1;
		string b = "";
		b += (char)('0' + ind);
		repn(i, 1, n){
			if(i == x){
				int tot = 0, tot1 = 0;
				rep(j, y){
					if(s[ind][j] == '1') tot += 1 - g[i][j];
					else tot += g[i][j];
				}
				repn(j, y, m){
					if(s[ind][j] == '1') tot1 += 1 - g[i][j];
					else tot1 += g[i][j];
				}
				if(!tot && tot1 == m - y) b += '0';
				else if(tot == y && !tot1) b += '1';
				else{
					ans = 0;
					break;
				}
			}
			else{
				if(!f[ind][i]){
					ans = 0;
					break;
				}
				if(x == -1 || i < x){
					if(nf[ind][i]) b += '1';
					else b += '0';
				}
				else{
					if(nf[ind][i]) b += '0';
					else b += '1';
				}
			}
		}
		if(ans){
			cout << "YES\n";
			cout << b << '\n';
			cout << s[ind] << '\n';
			exit(0);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];
	rep(i, 2){
		rep(j, m){
			if(g[0][j]){
				if(i) s[i] += '0';
				else s[i] += '1';
			}
			else{
				if(!i) s[i] += '0';
				else s[i] += '1';
			}
		}
		repn(k, 1, n){
			int tot = 0;
			rep(j, m){
				if(s[i][j] == '1') tot += 1 - g[k][j];
				else tot += g[k][j];
			}
			if(!tot || tot == m) f[i][k] = 1;
			if(tot == m) nf[i][k] = 1;
		}
	}
	solve(-1, -1);
	rep(i, n) rep(j, m) solve(i, j);
	cout << "NO\n";
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
