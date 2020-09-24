#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
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

void solve(){
	string a, b, p;
	cin >> a >> b >> p;
	int dp[a.size() + 1][b.size() + 1];
	rep(i, a.size() + 1) rep(j, b.size() + 1) dp[i][j] = 0;
	//it has to be a substring???
	//all letters in correct order
	//and p should have everything we need
	//lcs should be s!
	repn(i, 1, a.length() + 1) repn(j, 1, b.length() + 1){
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		if(a[i - 1] == b[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);	
	}
	int x = a.length();
	int y = b.length();
	string ans = "";
	while(x && y){
		if(a[x - 1] == b[y - 1]){
			ans += a[x - 1];
			x--, y--;
		}	
		else if(dp[x - 1][y] > dp[x][y - 1]) x--;
		else y--;
	}
	reverse(all(ans));
	if(ans != a){
		cout << "NO" << endl;
		return;
	}
	map<char, int> mp, mp1;
	rep(i, a.size()) mp[a[i]]++;
	rep(i, p.size()) mp[p[i]]++;
	rep(i, b.size()) mp1[b[i]]++;
	rep(i, b.size()){
		if(mp[b[i]] < mp1[b[i]]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
