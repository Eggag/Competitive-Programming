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
const int MAXN = 105;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int num[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi x(k), y(k);
	memset(num, 0, sizeof(num));
	rep(i, k){
		cin >> x[i] >> y[i], x[i]--, y[i]--;
		num[x[i]][y[i]]++;
	}
	vi xcnt(n, 0), ycnt(n, 0), lcnt(100 * n, 0), rcnt(100 * n, 0);
	rep(i, k){
		xcnt[x[i]]++;
		ycnt[y[i]]++;
		lcnt[y[i] + x[i]]++;
		rcnt[(((n - 1 - x[i]) + y[i]))]++;
	}
	int ans = 0;
	rep(i, n) rep(j, n){
		int ind = i + j;
		int ind1 = ((n - i - 1) + j);
		int sum = (((xcnt[i] + ycnt[j]) - num[i][j]) + ((lcnt[ind] + rcnt[ind1]) - num[i][j])) - num[i][j];
		if(sum == k) ans++;
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
