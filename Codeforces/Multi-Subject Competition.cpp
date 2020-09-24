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

vi m[100005];

bool cmp(vi a, vi b){
	return ((int)a.size() > (int)(b.size()));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m1;
	cin >> n >> m1;
	rep(i, n){
		int a, b;
		cin >> a >> b;
		a--;
		m[a].pb(b);
	}
	sort(m, m + m1, cmp);
	int mx = 0;
	rep(i, m1){
		mx = max(mx, (int)m[i].size());
		sort(m[i].rbegin(), m[i].rend());
		partial_sum(all(m[i]), m[i].begin());
	}
	int ans = 0;
	rep(i, mx){
		int cur = 0;
		rep(j, m1){
			if((int)m[j].size() <= i) break;
			if(m[j][i] > 0) cur += m[j][i];
		}
		ans = max(ans, cur);
	}
	cout << max(0, ans) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
