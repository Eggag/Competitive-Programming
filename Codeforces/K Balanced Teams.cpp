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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
int a[mxN], dp[mxN][mxN], mx[mxN][mxN]; //[the index][the group]

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	repn(i, 1, n + 1) cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[0][0] = 0;
	int ans = 0;
	repn(i, 1, n + 1){
		repn(j, 1, k + 1){
			int l = 1, r = i;
			while(l < r){
				int mid = (l + r) / 2;
				if(a[mid] >= (a[i] - 5)) r = mid;
				else l = mid + 1;
			}
			dp[i][j] = max(dp[i][j], (i - l + 1) + mx[j - 1][l - 1]);
			ans = max(ans, dp[i][j]);
			mx[j][i] = max(mx[j][i - 1], dp[i][j]);
		}
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
