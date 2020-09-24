#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl;
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
#define endl '\n'
const ld eps = 1e-6;
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
ld slope(ld x, ld y, ld x1, ld y1){
	return (ld)((y - y1) / (x - x1));
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	//cout << fixed << setprecision(15);
	vector<pair<ld, ld>> pos(m);
	rep(i, m){
		cin >> pos[i].se >> pos[i].fi;
	}
	sort(all(pos));
	vi cnt(n, 1);
	rep(i, m){
		repn(j, i + 1, m) if(pos[i].fi != pos[j].fi){
			//they form a line
			//so count the # of birds on it
			int cur = 0;
			if(pos[i].se == pos[j].se){
				if((ld)(pos[i].se) <= n){
					rep(k, m) if(pos[k].se == pos[i].se) cur++;
					cnt[(int)(pos[i].se) - 1] = max(cnt[(int)(pos[i].se) - 1], cur);
				}
			}
			else{
				ld s = slope(pos[i].se, pos[i].fi, pos[j].se, pos[j].fi);
				if(!s) continue;
				ld c = (ld)(pos[i].se - (ld)(pos[i].fi / s));
				int f = 1;
				int c1 = floor(c);
				if(abs(c - c1) > eps) f = 0;
				if(!f){
					//if it is 0.99999...
					int c2 = ceil(c);
					if(abs(c - c2) < eps) f = 1, c1 = c2;
				}
				if(f && c1 >= 1 && c1 <= n){
					//count them all
					rep(k, m){
						if(!(pos[k].se - c1)) continue;
						if((pos[k].fi / (pos[k].se - c1)) == s){
							cur++;
						}
					}
					cnt[c1 - 1] = max(cur, cnt[c1 - 1]);
				}
			}
		}
	}
	ll ans = 0;
	rep(i, n) ans += cnt[i];
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
