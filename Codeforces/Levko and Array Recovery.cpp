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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m1;
	cin >> n >> m1;
	vi t(m1), l(m1), r(m1), m(m1);	
	int nm = 0;
	rep(i, m1) cin >> t[i] >> l[i] >> r[i] >> m[i], l[i]--, r[i]--, nm += (t[i] == 2);
	int cnt = 0;
	vi vis(m1, 0), ans(n, -1e9);
	rep(i, n){
		int cur = 0, sb = -1e9, dif = 1e9;
		rep(j, m1){
			if(i >= l[j] && i <= r[j]){
				if(t[j] == 1) cur += m[j];
				else{
					if(m[j] < cur) sb = max(sb, cur - m[j]);
					else{
						dif = min(dif, m[j] - cur);
					}
				}
			}
		}
		int st = 0;
		if(sb != -1e9) st = -sb;
		else st = dif;
		ans[i] = st;
		rep(j, m1){
			if(i >= l[j] && i <= r[j]){
				if(t[j] == 1) st += m[j];
				else{
					assert(st <= m[j]);
					if(m[j] == st){
						if(!vis[j]) cnt++;
						vis[j] = 1;
					}
				}
			}
		}
	}
	if(cnt == nm){
		cout << "YES" << endl;
		rep(i, n) cout << ans[i] << " ";
		cout << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
