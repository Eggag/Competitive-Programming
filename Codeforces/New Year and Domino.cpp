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

int h[505][505], v[505][505];
string s[505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	memset(h, 0, sizeof(h));
	memset(v, 0, sizeof(v));
	rep(i, n){
		h[i][0] = 0;
		repn(j, 1, m){
			if(s[i][j - 1] == '.' && s[i][j] == '.') h[i][j] = h[i][j - 1] + 1;
			else h[i][j] = h[i][j - 1];
		}
	}
	rep(j, m){
		v[0][j] = 0;
		repn(i, 1, n){
			if(s[i - 1][j] == '.' && s[i][j] == '.') v[i][j] = v[i - 1][j] + 1;
			else v[i][j] = v[i - 1][j];
		}
	}
	int q;
	cin >> q;
	rep(i, q){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ans = 0;
		repn(i, a - 1, c) ans += h[i][d - 1] - h[i][b - 1];
		repn(j, b - 1, d) ans += v[c - 1][j] - v[a - 1][j];
		cout << ans << endl;
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
