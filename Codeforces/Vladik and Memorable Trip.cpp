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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN], cnt[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n + 1);
	repn(i, 1, n + 1){
		cin >> a[i];
		cnt[a[i]]++;
	}
	dp[0] = 0;
	repn(i, 1, n + 1){
		rep(j, i) dp[i] = max(dp[i], dp[j]);
		vi cnt1(mxN, 0);
		int uwu = 0, owo = 0;
		repn(j, i, n + 1){
			cnt1[a[j]]++;
			if(cnt1[a[j]] == 1) uwu++;
			if(cnt1[a[j]] == cnt[a[j]]){
				uwu--;
				owo ^= a[j];
			}
			if(!uwu) dp[j + 1] = max(dp[j + 1], dp[i] + owo);
		}

	}
	cout << max(dp[n + 1], dp[n]) << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
