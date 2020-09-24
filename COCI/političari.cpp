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

int g[505][505];
int bl[505][505]; //i blamed j

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ll k;
	cin >> n >> k;
	memset(bl, 0, sizeof(bl));
	repn(i, 1, n + 1) repn(j, 1, n + 1) cin >> g[i][j];
	pi cur = mp(1, 2);
	bl[2][1] = 1;
	vi ans = {1, 2};
	while(true){
		int nxt = g[cur.se][cur.fi];
		cur = mp(cur.se, nxt);
		if(bl[cur.se][cur.fi]){
			break;
		}
		bl[cur.se][cur.fi]++;
		ans.pb(nxt);
	}
	ans.pop_back();
	vi ans1;
	int st = 0;
	rep(i, ans.size()) if(i < ((int)ans.size() - 1)){
		if(!(ans[i] == cur.fi && ans[i + 1] == cur.se)) ans1.pb(ans[i]);
		else{
			st = i;
			break;
		}
	}
	vi ans2;
	if(k <= (int)ans1.size()){
		cout << ans1[k - 1] << endl;
		return 0;
	}
	repn(i, st, ans.size()) ans2.pb(ans[i]);
	k -= (int)ans1.size() + 1;
	if(!k){
		cout << ans2[0] << endl;
		return 0;
	}
	k %= (int)ans2.size();
	cout << ans2[k] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
