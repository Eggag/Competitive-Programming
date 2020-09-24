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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

string dp[105][105];
int g1[105][105];

string add(string ans, string s){
	string ans1 = "";
	int carry = 0;
	if(s.size() > ans.size()) swap(ans, s);
	rep(j, ans.size()){
		if((int)s.size() > j){
			int cur = (ans[j] - '0') + (s[j] - '0') + carry;
			carry = 0;
			ans1 += (char)((cur - ((cur / 10) * 10) + '0'));		
			if(cur >= 10) carry = cur / 10;
		}
		else{
			int cur = (ans[j] - '0') + carry;
			carry = 0;
			ans1 += (char)((cur - ((cur / 10) * 10) + '0'));
			if(cur >= 10) carry = cur / 10;
		}
	}
	if(carry) ans1 += (char)(carry + '0');
	ans = ans1;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) rep(j, n){
		cin >> g1[i][j];
	}
	rep(i, n) rep(j, n) dp[i][j] = "0";
	dp[0][0] = "1";
	rep(i, n) rep(j, n){
		if(!i && !j) continue;
		for(int k = i - 1; k >= 0; k--){
			if(g1[k][j] == (i - k)) dp[i][j] = add(dp[i][j], dp[k][j]);
		}
		for(int k = j - 1; k >= 0; k--){
			if(g1[i][k] == (j - k)) dp[i][j] = add(dp[i][j], dp[i][k]);
		}
	}
	reverse(all(dp[n - 1][n - 1]));
	cout << dp[n - 1][n - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
