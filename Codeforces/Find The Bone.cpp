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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int st[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	rep(i, m){
		int h;
		cin >> h;
		st[h] = 1;
	}
	vector<pi> p(k);
	rep(i, k) cin >> p[i].fi >> p[i].se;
	int pos = 1;
	if(st[pos]){
		cout << pos << endl;
		return 0;
	}
	rep(i, k){
		int u = p[i].fi, v = p[i].se;
		if(u == pos){
			pos = v;
			if(st[pos]){
				cout << pos << endl;
				return 0;
			}
		}
		else if(v == pos){
			pos = u;
			if(st[pos]){
				cout << pos << endl;
				return 0;
			}
		}
	}
	cout << pos << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
