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

char g[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	rep(i, n) rep(j, m){
		cin >> g[i][j];
		if(g[i][j] == 'B') cnt++;
	}
	if(!cnt){
		cout << 1 << endl;
		return 0;
	}
	int f = 1e9, l = 0;
	rep(i, n){
		rep(j, m){
			if(g[i][j] == 'B'){
				f = min(f, j);
				break;
			}
		}
		for(int j = m - 1; j >= 0; j--){
			if(g[i][j] == 'B'){
				l = max(l, j);	
			}
		}
	}
	int len = l - f + 1;
	f = 1e9, l = 0;
	rep(j, m){
		rep(i, n){
			if(g[i][j] == 'B'){
				f = min(f, i);
				break;
			}
		}
		for(int i = n - 1; i >= 0; i--){
			if(g[i][j] == 'B'){
				l = max(l, i);	
			}
		}
	}
	int len1 = l - f + 1;
	if(len > len1){
		if(len > n){
			cout << -1 << endl;	
		}
		else{
			cout << (len * len) - cnt << endl;
		}
	}
	else{
		if(len1 > m){
			cout << -1 << endl;
		}
		else{
			cout << (len1 * len1) - cnt << endl;
		}
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
