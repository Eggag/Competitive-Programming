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
const int mxN = 2005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int num[mxN][mxN];
int mn[mxN], mx[mxN];
int num1[mxN][mxN];
int mn1[mxN], mx1[mxN];
int d[mxN], r[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	rep(i, n) mn[i] = 1e9, mx[i] = 0;
	rep(i, n) mn1[i] = 1e9, mx1[i] = 0;
	rep(i, n) rep(j, n) if(s[i][j] == 'B'){
		mn[j] = min(mn[j], i);
		mx[j] = max(mx[j], i);
	}
	rep(i, n) rep(j, n) if(s[i][j] == 'B'){
		mn1[i] = min(mn1[i], j);
		mx1[i] = max(mx1[i], j);
	}
	rep(i, n - k + 1){
		num[i][0] = 0;
		vi gd(n, 0);
		rep(j, k){
			if(mn[j] >= i && mx[j] <= i + k - 1) num[i][0]++, gd[j] = 1;
		}
		repn(j, 1, n - k + 1){
			num[i][j] = num[i][j - 1];
			if(gd[j - 1]) num[i][j]--;
			if(mn[j + k - 1] >= i && mx[j + k - 1] <= i + k - 1) num[i][j]++, gd[j + k - 1] = 1;
		}
	}
	rep(j, n - k + 1){
		num1[0][j] = 0;
		vi gd(n, 0);
		rep(i, k){
			if(mn1[i] >= j && mx1[i] <= j + k - 1) num1[0][j]++, gd[i] = 1;
		}
		repn(i, 1, n - k + 1){
			num1[i][j] = num1[i - 1][j];
			if(gd[i - 1]) num1[i][j]--;
			if(mn1[i + k - 1] >= j && mx1[i + k - 1] <= j + k - 1) num1[i][j]++, gd[i + k - 1] = 1;
		}
	}
	rep(i, n){
		if(i) d[i] = d[i - 1];
		int f = 1;
		rep(j, n) if(s[i][j] == 'B') f = 0;
		d[i] += f;
	}
	rep(j, n){
		if(j) r[j] = r[j - 1];
		int f = 1;
		rep(i, n) if(s[i][j] == 'B') f = 0;
		r[j] += f;
	}
	int ans = 0;
	rep(i, n - k + 1) rep(j, n - k + 1){
		int cur = num[i][j] + num1[i][j];
		cur += r[n - 1] - (r[j + k - 1] - (j ? r[j - 1] : 0));
		cur += d[n - 1] - (d[i + k - 1] - (i ? d[i - 1] : 0));
		ans = max(ans, cur);
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
