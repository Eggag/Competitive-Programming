#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
	string t, p;
	cin >> t >> p;
	int n = (int)(t.size());
	int m = (int)(p.size());
	vi a(n), b(n);
	rep(i, n){
		cin >> a[i];
		b[a[i] - 1] = i + 1;
	}
	int l = 0, r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		int cr = 0;
		rep(i, n) if(b[i] > mid){
			if(t[i] == p[cr]) cr++;
			if(cr == m) break;
		}
		if(cr == m) l = mid;
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
