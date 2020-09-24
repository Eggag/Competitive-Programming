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

string s[105];
int vis[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	vector<pair<pi, int>> ans;
	rep(i, 105) rep(j, 105) vis[i][j] = 0;
	rep(i, n) rep(j, m){
		if(s[i][j] == '*'){
			int i1 = i + 1;
			int cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
			while(i1 < n && s[i1][j] == '*') i1++, cnt++;
			i1 = i - 1;
			while(i1 >= 0 && s[i1][j] == '*') i1--, cnt1++;
			int j1 = j + 1;
			while(j1 < m && s[i][j1] == '*') j1++, cnt2++;
			j1 = j - 1;
			while(j1 >= 0 && s[i][j1] == '*') j1--, cnt3++;
			int e = min({cnt, cnt1, cnt2, cnt3});
			if(e){
				vis[i][j] = 1;
				ans.pb(mp(mp(i + 1, j + 1), e));
				int m = i + 1;
				int e1 = e;
				while(e1--) vis[m][j] = 1, m++; 
				e1 = e;
				m = i - 1;
				while(e1--) vis[m][j] = 1, m--; 
				e1 = e;
				m = j + 1;
				while(e1--) vis[i][m] = 1, m++; 
				e1 = e;
				m = j - 1;
				while(e1--) vis[i][m] = 1, m--; 
			}
		}
	}
	rep(i, n) rep(j, m) if(s[i][j] == '*' && !vis[i][j]){
		cout << -1 << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for(pair<pi, int> x : ans) cout << x.fi.fi << " " << x.fi.se << " " << x.se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

