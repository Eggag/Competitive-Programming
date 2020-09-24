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

bool cmp(pi a, pi b){
	return a.fi < b.fi;
}

void solve(){
	int n, m;
	cin >> n >> m;
	int ans = n; //do the rows
	char res[n + 1][m + 1];
	rep(i, n) rep(j, m) res[i][j] = '+';
	priority_queue<pi, vector<pi>, function<bool(pi, pi)>> pq(cmp);
	rep(i, n) if(((m - 1) / 2) > 0) pq.push(mp((m - 1) / 2, i));
	rep(j, m){
		int need = (n + 2) / 2; //how many need to be changed
		vector<pi> add;
		while(need && pq.size()){
			pi cur = pq.top();
			pq.pop();
			need--;
			res[cur.se][j] = '-';
			add.pb(mp(cur.fi - 1, cur.se));
		}
		if(need) break;
		else ans++;
		rep(i, add.size()) if(add[i].fi) pq.push(add[i]);
	}
	int ans1 = m;
	priority_queue<pi, vector<pi>, function<bool(pi, pi)>> pq1(cmp);
	rep(i, m) if(((n - 1) / 2) > 0) pq1.push(mp((n - 1) / 2, i));
	char res1[n + 1][m + 1];
	rep(i, n) rep(j, m) res1[i][j] = '-';
	rep(i, n){
		int need = (m + 2) / 2; //how many need to be changed
		vector<pi> add;
		while(need && pq1.size()){
			pi cur = pq1.top();
			pq1.pop();
			need--;
			res1[i][cur.se] = '+';
			add.pb(mp(cur.fi - 1, cur.se));
		}
		if(need) break;
		else ans1++;
		rep(i, add.size()) if(add[i].fi) pq1.push(add[i]);
	}
	if(ans > ans1){
		cout << ans << endl;
		rep(i, n){
			rep(j, m) cout << res[i][j];
			cout << endl;
		}
	}
	else{
		cout << ans1 << endl;
		rep(i, n){
			rep(j, m) cout << res1[i][j];
			cout << endl;
		}
	}
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
	- Array bounds
	- Special cases
Be careful!
*/
