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

void solve(){
	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i, n) cin >> a[i], b[i] = a[i];
	vi gd(n, -1), gdR(n, -1);
	gd[0] = b[0];
	rep(i, n - 1){
		if(b[i] > b[i + 1]) break;
		b[i + 1] -= b[i];
		gd[i + 1] = b[i + 1];
	}
	rep(i, n) b[i] = a[i];
	gdR[n - 1] = b[n - 1];
	for(int i = n - 2; i >= 0; i--){
		if(b[i] < b[i + 1]) break;
		b[i] -= b[i + 1];
		gdR[i] = b[i];
	}
	int f = 0;
	rep(i, n - 1){
		if(!i){
			int nxt = i + 2;
			if(nxt < n){
				nxt = gdR[i + 2];
				if(nxt != -1){
					if((a[i + 1] + nxt) == a[i]) f = 1;
				}
			}
			else if(a[i] == a[i + 1]) f = 1;
		}
		else if(i == (n - 2) && i != 0){
			int nxt = gd[i - 1];
			if(nxt != -1){
				if((a[i] + nxt) == a[i + 1]) f = 1;
			}
		}
		else{
			int nxt = gd[i - 1], nxt1 = gdR[i + 2];
			if(nxt != -1 && nxt1 != -1){
				if((a[i + 1] - nxt) == (a[i] - nxt1) && (a[i] - nxt1) >= 0) f = 1;
			}
		}
	}
	rep(i, n - 1){
		if(!i){
			int nxt = i + 2;
			if(nxt < n){
				nxt = gdR[i + 2];
				if(nxt != -1){
					if((a[i] + nxt) == a[i + 1]) f = 1;
				}
			}
			else if(a[i] == a[i + 1]) f = 1;
		}
		else if(i == (n - 2) && i != 0){
			int nxt = gd[i - 1];
			if(nxt != -1){
				if((a[i + 1] + nxt) == a[i]) f = 1;
			}
		}
		else{
			int nxt = gd[i - 1], nxt1 = gdR[i + 2];
			if(nxt != -1 && nxt1 != -1){
				if((a[i] - nxt) == (a[i + 1] - nxt1) && (a[i + 1] - nxt1) >= 0) f = 1;
			}
		}
	}
	cout << (f ? "YES" : "NO") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
