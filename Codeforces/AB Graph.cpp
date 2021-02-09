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
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

char g[mxN][mxN];

void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, n) cin >> g[i][j];
	rep(i, n) rep(j, n) if(i != j && (g[i][j] == g[j][i] || (m & 1))){
		cout << "YES" << '\n';
		rep(k, m + 1){
			if(k % 2 == 0) cout << i + 1 << " ";
			else cout << j + 1 << " ";
		}
		cout << '\n';
		return;
	}
	if(m % 2 == 0){
		rep(ch, 2) rep(i, n){
			int f = -1, s = -1;
			char c = (char)('a' + ch);
			rep(j, n){
				if(g[i][j] == c && f == -1) f = j;
				else if(g[j][i] == c && s == -1) s = j;
			}
			if(~f && ~s){
				cout << "YES" << '\n';
				if(m % 4 == 2){
					//s -> i -> f -> i
					rep(k, m + 1){
						if(k % 4 == 0) cout << s + 1 << " ";
						else if(k % 4 == 1 || k % 4 == 3) cout << i + 1 << " ";
						else cout << f + 1 << " ";
					}
					cout << '\n';
					return;
				}
				else{
					//i -> s -> i -> f
					rep(k, m + 1){
						if(k % 4 == 0 || k % 4 == 2) cout << i + 1 << " ";
						else if(k % 4 == 1) cout << s + 1 << " ";
						else cout << f + 1 << " ";
					}
					cout << '\n';
					return;
				}
			}
			f = -1, s = -1;
			rep(j, n){
				if(g[j][i] == c && s == -1) s = j;
				else if(g[i][j] == c && f == -1) f = j;
			}
			if(~f && ~s){
				cout << "YES" << '\n';
				if(m % 4 == 2){
					//s -> i -> f -> i
					rep(k, m + 1){
						if(k % 4 == 0) cout << s + 1 << " ";
						else if(k % 4 == 1 || k % 4 == 3) cout << i + 1 << " ";
						else cout << f + 1 << " ";
					}
					cout << '\n';
					return;
				}
				else{
					//i -> s -> i -> f
					rep(k, m + 1){
						if(k % 4 == 0 || k % 4 == 2) cout << i + 1 << " ";
						else if(k % 4 == 1) cout << s + 1 << " ";
						else cout << f + 1 << " ";
					}
					cout << '\n';
					return;
				}
			}
		}
	}
	cout << "NO" << '\n';
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
