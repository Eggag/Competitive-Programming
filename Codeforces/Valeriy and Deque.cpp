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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	deque<int> dq(n);
	int mx = 0;
	vector<pi> ans;
	rep(i, n) cin >> dq[i], mx = max(mx, dq[i]);
	while(dq[0] != mx){
		int a = dq.front(); dq.pop_front();
		int b = dq.front(); dq.pop_front();
		ans.pb(mp(a, b));
		dq.push_front(max(a, b));
		dq.pb(min(a, b));
	}
	rep(i, q){
		ll m;
		cin >> m;
		m--;
		if(m < ans.size()){
			cout << ans[m].fi << " " << ans[m].se << endl;	
		}
		else{
			m -= ans.size();
			int p = 1 + (m % (n - 1));
			cout << dq[0] << " " << dq[p] << endl;
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
