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
const int mxN = 205;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int st[mxN], en[mxN];
int dp[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	int f2 = 1;
	rep(i, n){
		cin >> p[i].fi >> p[i].se;
		if(p[i].fi != -1 && p[i].se != -1){
			if(p[i].fi >= p[i].se){
				f2 = 0;
			}
		}
		if(p[i].fi != -1){
			if(en[p[i].fi]) f2 = 0;
			if(st[p[i].fi]) f2 = 0;
			st[p[i].fi] = p[i].se;
		}
		if(p[i].se != -1){
			if(en[p[i].se]) f2 = 0;
			if(st[p[i].se]) f2 = 0;
			en[p[i].se] = p[i].fi;
		}
	}
	if(!f2){
		cout << "No" << endl;
		return 0;
	}
	dp[0] = 1;
	rep(i, 2 * n + 1) if(dp[i]){
		rep(k, n + 1){
			//so k is b - a - 1
			int nm = (k + 1) * 2;
			if((i + nm) > (2 * n)) continue;
			int f1 = 1;
			repn(l, i + 1, i + k + 2){
				if(st[l] && st[l] != -1){
					if((st[l] - l - 1) != k){
						f1 = 0;
						break;
					}
				}
				if(st[l] && st[l] == -1){
					if(en[l + k + 1]) f1 = 0;
				}
				if(en[l]){
					f1 = 0;
					break;
				}
			}	
			repn(l, i + k + 2, i + nm + 1){
				if(st[l]){
					f1 = 0;
					break;
				}
				if(en[l] && en[l] != -1){
					if((l - en[l] - 1) != k){
						f1 = 0;
						break;
					}
				}
				if(en[l] && en[l] == -1){
					if(st[l - k - 1]) f1 = 0;
				}
			}
			if(f1) dp[i + nm] = 1;
		}	
	}
	cout << (dp[2 * n] ? "Yes" : "No") << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
