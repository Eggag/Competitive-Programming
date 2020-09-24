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
	int n;
	cin >> n;
	vi a(n);
	map<int, int> m;
	rep(i, n) cin >> a[i], m[a[i]]++;
	vi g;
	int mx = 0;
	for(pi x : m) g.pb(x.se), mx = max(mx, x.se);
	sort(all(g));
	int ans = 0;
	n = g.size();
	repn(i, 1, mx + 1){
		int cur = 0;
		//keep taking the first with the element we need
		int need = i;
		int prev = -1;
		while(true){
			int l = prev + 1, r = n - 1;
			while(l < r){
				//now binary search for the first element with enough
				int mid = (l + r) / 2;
				if(g[mid] >= need) r = mid;
				else l = mid + 1;
			}
			if(l >= n || (g[l] < need)) break; //too bad
			prev = l;
			cur += need;
			need *= 2;
		}
		ans = max(ans, cur);
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
