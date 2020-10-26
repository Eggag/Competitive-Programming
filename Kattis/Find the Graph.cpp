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

int ans[55][55];

int query(vi a){
	cout << "? " << (int)(a.size());
	rep(i, a.size()) cout << " " << a[i] + 1;
	cout << endl;
	int ret;
	cin >> ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi q(n);
	rep(i, n) q[i] = query({i});
	rep(i, n) repn(j, i + 1, n){
		if(query({i, j}) != (q[i] + q[j])) ans[i][j] = ans[j][i] = 1;
	}
	cout << "!" << endl;
	rep(i, n){
		rep(j, n) cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
