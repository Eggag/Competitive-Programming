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

string s[2];
int vis[105][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	rep(i, 2) cin >> s[i];	
	rep(i, 105) rep(j, 2) vis[i][j] = 0;
	int ans = 0;
	rep(i, ((int)s[0].size() - 1)){
		if(s[0][i] == '0' && s[1][i] == '0' && s[1][i + 1] == '0'){
			if(!vis[i][0] && !vis[i][1] && !vis[i + 1][1]){
				ans++;
				vis[i][0] = 1;
				vis[i][1] = 1;
				vis[i + 1][1] = 1;
			}
		}
		if(s[0][i] == '0' && s[1][i] == '0' && s[0][i + 1] == '0'){
			if(!vis[i][0] && !vis[i][1] && !vis[i + 1][0]){
				ans++;
				vis[i][0] = 1;
				vis[i][1] = 1;
				vis[i + 1][0] = 1;
			}
		}
		if(s[0][i + 1] == '0' && s[1][i + 1] == '0' && s[1][i] == '0'){
			if(!vis[i + 1][0] && !vis[i + 1][1] && !vis[i][1]){
				ans++;
				vis[i + 1][0] = 1;
				vis[i + 1][1] = 1;
				vis[i][1] = 1;
			}
		}
		if(s[0][i + 1] == '0' && s[1][i + 1] == '0' && s[0][i] == '0'){
			if(!vis[i + 1][0] && !vis[i + 1][1] && !vis[i][0]){
				ans++;
				vis[i + 1][0] = 1;
				vis[i + 1][1] = 1;
				vis[i][0] = 1;
			}
		}
	}
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
