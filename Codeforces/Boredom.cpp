#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int MAXN = 1e5 + 5;

int cnt[MAXN];
ll dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int x;
	rep(i, n){
		cin >> x;
		cnt[x]++;
	}
	dp[0] = 0;
	dp[1] = cnt[1];
	repn(i, 2, MAXN){
		dp[i] = (ll)i * cnt[i]; 
		dp[i] += dp[i - 2];
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[MAXN - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
