#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n + 1];
	repn(i, 1, n + 1) cin >> a[i];
	int r[n + 2] = {0}, l[n + 2] = {0};
	repn(i, 1, n + 1) l[i] = gcd(a[i], l[i - 1]);
	for(int i = n; i >= 1; i--) r[i] = gcd(r[i + 1], a[i]);
	int ans = 1;
	repn(i, 1, n + 1){
		ans = max(ans, gcd(l[i - 1], r[i + 1]));
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
