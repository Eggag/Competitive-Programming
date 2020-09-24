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

double p[1005];
int d[1005];
double dp[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, l, D;
	cin >> n >> l >> D;
	repn(i, 1, n + 1) cin >> p[i];
	repn(i, 1, n + 1) cin >> d[i];
	n++;
	dp[0] = 1.0;
	p[n] = 1.0;
	d[n] = D;
	repn(i, 1, n + 1){
		rep(j, i) if(d[i] - d[j] <= l){
			dp[i] = max(dp[i], dp[j] * p[i]);
		}
	}
	if(dp[n]) cout << fixed << setprecision(6) << dp[n] << endl;
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
