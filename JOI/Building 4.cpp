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

int a[mxN][2];
int mx[mxN][2], mn[mxN][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	n *= 2;
	rep(j, 2) repn(i, 1, n + 1) cin >> a[i][j];
	repn(i, 1, n + 1){
		rep(j, 2){ //what we take
			mn[i][j] = 1e9, mx[i][j] = -1e9;
			rep(k, 2){
				//what we update from
				if(mn[i - 1][k] < 0 || a[i][j] < a[i - 1][k]) continue;
				mn[i][j] = min(mn[i][j], mn[i - 1][k] + (j == 0));
				mx[i][j] = max(mx[i][j], mx[i - 1][k] + (j == 0));
			}
		}
	}
	vi ans;
	if(mn[n][0] <= n / 2 && mx[n][0] >= n / 2) ans.pb(0);
	else if(mn[n][1] <= n / 2 && mx[n][1] >= n / 2) ans.pb(1);
	else{
		cout << -1 << endl;
		return 0;
	}
	int len = n / 2;
	for(int i = n - 1; i >= 1; i--){
		int lst = ans.back();
		if(lst == 0) len--;
		rep(j, 2){
			if(mx[i][j] < 0 || a[i + 1][lst] < a[i][j]) continue;
			if(mn[i][j] <= len && mx[i][j] >= len){
				ans.pb(j);
				break;
			}
		}
	}
	for(int i = n - 1; i >= 0; i--) cout << (char)('A' + ans[i]);
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
