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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];
	//do rows and columns for both
	ll ans = 0;
	rep(i, n){
		ll num[m], num1[m];
		rep(j, m) num[j] = 0;
		rep(j, m) num1[j] = 0;
		rep(j, m){
			if(g[i][j] == 1){
				for(int k = j; k >= 1; k--){
					num[k] += num[k - 1];
				}	
				num[0]++;
			}
			else{
				for(int k = j; k >= 1; k--){
					num1[k] += num1[k - 1];
				}	
				num1[0]++;
			}
		}
		rep(j, m) ans += num[j];
		rep(j, m) ans += num1[j];
	}
	rep(j, m){
		ll num[n], num1[n];
		rep(i, n) num[i] = 0;
		rep(i, n) num1[i] = 0;
		rep(i, n){
			if(g[i][j] == 1){
				for(int k = i; k >= 1; k--){
					num[k] += num[k - 1];
				}	
				num[0]++;
			}
			else{
				for(int k = i; k >= 1; k--){
					num1[k] += num1[k - 1];
				}	
				num1[0]++;
			}
		}
		repn(i, 1, n) ans += num[i];
		repn(i, 1, n) ans += num1[i];
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
