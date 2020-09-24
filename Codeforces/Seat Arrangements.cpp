#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

string s[2005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	rep(i, n) cin >> s[i];
	int ans = 0;
	//rows
	rep(i, n) rep(j, m){
		int cur = j;
		while(j < m && s[i][j] == '.') j++;
		ans += max(0, j - cur - k + 1);
	}
	//colums
	//only if n > 1
	rep(j, m) rep(i, n){
		int cur = i;
		while(i < n && s[i][j] == '.') i++;
		ans += max(0, i - cur - k + 1);
	}
	if(k == 1) ans /= 2;
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
