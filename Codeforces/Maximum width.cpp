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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int cr = 0;
	vi le(n, 0), ri(n, 0);
	rep(i, n){
		if(cr < m && s[i] == t[cr]) cr++;
		le[i] = cr;
	}
	cr = m - 1;
	for(int i = n - 1; i >= 0; i--){
		if(cr && s[i] == t[cr]) cr--;
		ri[i] = cr;
	}
	int l = 1, r = n - 1;
	while(l < r){
		int mid = (l + r + 1) / 2, f = 0;
		rep(i, n - mid) if(le[i] > ri[i + mid] && le[i] != m && le[i] != 0){
			f = 1;	
			break;
		}
		if(f) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
