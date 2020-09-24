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
 
int g[505][2];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k, c;
	cin >> n >> k >> c;
	rep(i, n) rep(j, k) cin >> g[i][j];
	if(k == 1){
		vi t;
		rep(i, n) t.pb(g[i][0]);
		sort(all(t));
		reverse(all(t));
		cout << t[c - 1] << endl;
	}
	else{
		vi t;
		rep(i, n) repn(j, i + 1, n) t.pb(max(g[i][0], g[j][0]) + max(g[i][1], g[j][1]));
		sort(all(t));
		reverse(all(t));
		cout << t[c - 1] << endl;
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
