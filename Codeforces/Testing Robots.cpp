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
	int x, y, x0, y0;
	cin >> x >> y >> x0 >> y0;
	string s;
	cin >> s;
	int n = s.size();
	vi ans(n + 1, 0);
	map<pi, int> cnt, vis;
	cnt[mp(x0, y0)] = 1;
	vis[mp(x0, y0)] = 1;
	rep(i, s.size()){
		if(s[i] == 'L') if(y0 > 1){
			y0--;
			if(!vis[mp(x0, y0)]){
				cnt[mp(x0, y0)] = i + 2;
				vis[mp(x0, y0)] = 1;
			}
		}
		if(s[i] == 'R') if(y0 < y){
			y0++;
			if(!vis[mp(x0, y0)]){
				cnt[mp(x0, y0)] = i + 2;
				vis[mp(x0, y0)] = 1;
			}
		}
		if(s[i] == 'U') if(x0 > 1){
			x0--;
			if(!vis[mp(x0, y0)]){
				cnt[mp(x0, y0)] = i + 2;
				vis[mp(x0, y0)] = 1;
			}
		}
		if(s[i] == 'D') if(x0 < x){
			x0++;
			if(!vis[mp(x0, y0)]){
				cnt[mp(x0, y0)] = i + 2;
				vis[mp(x0, y0)] = 1;
			}
		}
	}
	int tot = 0;
	repn(i, 1, x + 1) repn(j, 1, y + 1){
		if(cnt[mp(i, j)]) ans[cnt[mp(i, j)] - 1]++, tot++;
	}
	ans[n] += (x * y) - tot;
	rep(i, n + 1) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
