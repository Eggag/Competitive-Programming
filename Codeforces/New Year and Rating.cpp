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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int f1 = 0;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se, f1 |= p[i].se;
	if(!(f1 & 2)) cout << "Infinity" << endl;
	else if(!(f1 & 1)){
		int mx = 0;
		int cur = 0;
		rep(i, n - 1) cur += p[i].fi, mx = max(mx, cur);
		int st = 1899 - mx;
		rep(i, n) st += p[i].fi;
		cout << st << endl;
	}
	else{
		rep(i, n - 1){
			if(p[i].se == 1 && p[i + 1].se == 2){
				if(p[i].fi >= 0){
					cout << "Impossible" << endl;
					return 0;
				}
				int bst = 0, res = -1;
				for(int j = 1899 - p[i].fi; j >= 1900; j--){
					int f = 1;
					int nw = j;
					for(int k = i; k < n; k++){
						if(p[k].se == 1 && nw < 1900) f = 0;
						if(p[k].se == 2 && nw >= 1900) f = 0;
						nw += p[k].fi;
					}
					int mx = nw;
					nw = j;
					for(int k = i - 1; k >= 0; k--){
						nw -= p[k].fi;
						if(p[k].se == 1 && nw < 1900) f = 0;
						if(p[k].se == 2 && nw >= 1900) f = 0;
					}
					if(f){
						bst = j;
						res = mx;
						break;
					}
				}
				if(!bst) cout << "Impossible" << endl;
				else cout << res << endl;
				return 0;
			}
			if(p[i].se == 2 && p[i + 1].se == 1){
				if(p[i].fi <= 0){
					cout << "Impossible" << endl;
					return 0;
				}
				int bst = 0, res = -1;
				for(int j = 1899; j >= (1900 - p[i].fi); j--){
					int f = 1;
					int nw = j;
					for(int k = i; k < n; k++){
						if(p[k].se == 1 && nw < 1900) f = 0;
						if(p[k].se == 2 && nw >= 1900) f = 0;
						nw += p[k].fi;
					}
					int mx = nw;
					nw = j;
					for(int k = i - 1; k >= 0; k--){
						nw -= p[k].fi;
						if(p[k].se == 1 && nw < 1900) f = 0;
						if(p[k].se == 2 && nw >= 1900) f = 0;
					}
					if(f){
						bst = j;
						res = mx;
						break;
					}
				}
				if(!bst) cout << "Impossible" << endl;
				else cout << res << endl;
				return 0;
			}
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
