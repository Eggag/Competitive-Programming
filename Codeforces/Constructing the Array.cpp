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
	if(a.fi != b.fi) return a.fi < b.fi;
	else return a.se > b.se;
}

void solve(){
	int n;
	cin >> n;
	priority_queue<pi, vector<pi>, function<bool(pi, pi)>> pq(cmp);
	vi ans(n, 0);
	pq.push({n, 0});
	rep(i, n){
		pi cur = pq.top();
		pq.pop();
		if(cur.fi % 2 == 0){
			int mid = (cur.se + cur.se + cur.fi - 1) / 2;
			ans[mid] = i + 1;
			pq.push({mid - cur.se, cur.se});
			pq.push({(cur.fi - 1 - (mid - cur.se)), mid + 1});
		}
		else{
			int mid = (cur.se + cur.se + cur.fi) / 2;
			ans[mid] = i + 1;
			pq.push({mid - cur.se, cur.se});
			pq.push({(cur.fi - 1 - (mid - cur.se)), mid + 1});
		}
	}
	rep(i, n) cout << ans[i] << " ";
	cout << endl;
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
