#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

set<int> ans;

void dfs(vi x, vi y, int cnt, int a1){
	if(cnt == 5){
		ans.insert(a1);
		return;
	}
	if(cnt & 1){
		rep(i, x.size()){
			vi cur;
			rep(j, x.size()) if(j != i){
				cur.pb(x[j]);
			}
			vi cur1 = y;
			cur1.pb(x[i]);
			dfs(cur, cur1, cnt + 1, a1 - x[i]);
		}
	}
	else{
		rep(i, y.size()){
			vi cur;
			rep(j, y.size()) if(j != i){
				cur.pb(y[j]);
			}
			vi cur1 = x;
			cur1.pb(y[i]);
			dfs(cur1, cur, cnt + 1, a1 + y[i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);
	vi a(10), b(10);
	rep(i, 10) cin >> a[i];
	rep(i, 10) cin >> b[i];
	dfs(a, b, 1, 1000);
	cout << ans.size() << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
