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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<ld> p(n), sum(n);
	rep(i, n){
		ld x;
		cin >> x;
		if(x == 1) p[i] = 1.0;
		else p[i] = (ld)(x / 2) + 0.5;
		if(!i) sum[i] = p[i];
		else sum[i] = sum[i - 1] + p[i];
	}
	ld ans = 0;
	repn(i, k - 1, n){
		int j = i - k;
		ld num;
		if(j == -1) num = 0;
		else num = sum[j];
		ans = max(ans, sum[i] - num);
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
