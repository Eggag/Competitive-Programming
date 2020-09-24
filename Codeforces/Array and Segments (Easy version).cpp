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
	int n, m;
	cin >> n >> m;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi l(m), r(m);
	rep(i, m) cin >> l[i] >> r[i], l[i]--, r[i]--;
	int best = 0;
	vi seg;
	rep(i, n){
		vi cur;
		vi cnt(n + 1, 0);
		rep(j, m) if(!(i >= l[j] && i <= r[j])){
			cur.pb(j);
			cnt[l[j]]--;
			cnt[r[j] + 1]++;
		}
		int mn = 1e9, mx = -1e9;
		partial_sum(all(cnt), cnt.begin());
		rep(j, n) cnt[j] += a[j], mx = max(mx, cnt[j]), mn = min(mn, cnt[j]);
		/*
		debug(i);
		rep(j, cnt.size()) cout << cnt[j] << " ";
		cout << endl;
		cout << "-----" << endl;
		*/
		if((mx - mn) > best) seg = cur, best = mx - mn;
	}
	cout << best << endl;
	cout << seg.size() << endl;
	for(int x : seg) cout << x + 1 << " ";
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
