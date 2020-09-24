#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, 100005) g[i] = 1;
	rep(i, n){
		int p, c;
		cin >> p >> c;
		if(p == -1){
			g[i] = 0;
			continue;
		}
		p--;
		if(!c) g[p] = 0, g[i] = 0;
	}
	vi ans;
	rep(i, n) if(g[i]) ans.pb(i);
	if(!ans.size()) cout << -1 << endl;
	else{
		rep(i, ans.size()) cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
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
