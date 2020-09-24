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

ll dp[20][15][15][15];
ll dp1[20][15][15][15][2];

string to_str(ll num){
	string ret = "";
	while(num){
		ret += (char)((num % 10) + '0');
		num /= 10;
	}
	reverse(all(ret));
	return ret;
}

ll solve(ll n){
	if(n < 0) return 0;
	if(n <= 100000){
		ll ret = 0;
		rep(i, n + 1){
			string s = to_str(i);
			int f = 1;
			rep(i, s.size() - 1){
				if(s[i] == s[i + 1]) f = 0;
			}
			rep(i, s.size() - 2){
				if(s[i] == s[i + 2]) f = 0;
			}
			if(f) ret++;
		}	
		return ret;
	}
	string s = to_str(n);
	int m = s.size();
	ll ans = 0LL;
	repn(i, 1, m){
		if(i == 1){
			ans += 10;
			continue;
		}
		if(i == 2){
			ans += 81;
			continue;
		}
		rep(j, 20) rep(k, 10) rep(l, 10) rep(p, 10) dp[j][k][l][p] = 0LL;
		dp[0][0][0][0] = 1LL;
		repn(j, 1, i + 1){
			rep(k, 10) rep(l, 10) rep(f, 10) rep(p, 10){
				if(j == 1 && !k) continue;
				if(j == 2 && k == l) continue;
				if(j > 2 && (k == f || k == l || l == f)) continue;
				if(j > 3 && (l == p || f == p)) continue;
				dp[j][k][l][f] += dp[j - 1][l][f][p];
			}
		}
		rep(k, 10) rep(l, 10) rep(f, 10) ans += dp[i][k][l][f]; 
	}
	rep(j, 20) rep(k, 10) rep(l, 10) rep(p, 10) rep(o, 2) dp1[j][k][l][p][o] = 0LL;
	dp1[0][0][0][0][0] = 1LL;
	repn(j, 1, m + 1){
		rep(k, 10) rep(l, 10) rep(f, 10) rep(p, 10){
			if(j == 1 && !k) continue;
			if(j == 2 && k == l) continue;
			if(j > 2 && (k == f || k == l || l == f)) continue;
			if(j > 3 && (l == p || f == p)) continue;
			int dig = (int)(s[j - 1] - '0');
			if(k < dig){
				dp1[j][k][l][f][1] += (dp1[j - 1][l][f][p][0] + dp1[j - 1][l][f][p][1]);
			}
			else if(k == dig){
				dp1[j][k][l][f][1] += dp1[j - 1][l][f][p][1];
				dp1[j][k][l][f][0] += dp1[j - 1][l][f][p][0];
 			}
			else{
				dp1[j][k][l][f][1] += dp1[j - 1][l][f][p][1];
			}
		}
	}
	rep(k, 10) rep(l, 10) rep(f, 10){
		ll add = dp1[m][k][l][f][0] + dp1[m][k][l][f][1];
		ans += add;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll a, b;
	cin >> a >> b;
	cout << solve(b) - solve(a - 1) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
