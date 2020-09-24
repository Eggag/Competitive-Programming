#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
	rep(i, n) cin >> a[i];
	sort(all(a));
	int l = 0, r = n / 2 - (n % 2 == 0);
	while(l < r){
		int mid = (l + r + 1) / 2;
		int cur = mid;
		while(cur < n && a[cur] == a[0]) cur++;
		int f = 1;
		if(cur >= n) f = 0;
		cur++;
		repn(i, 1, mid){
			if(cur >= n) f = 0;
			while(cur < n && a[cur] == a[i]) cur++;
			cur++;
		}
		if(cur >= n) f = 0;
		while(cur < n && a[cur] == a[mid - 1]) cur++;
		if(cur >= n) f = 0;
		if(f) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	vi res;
	vi vis(n, 0);
	if(l){
		int cur = l;
		while(a[cur] == a[0]) cur++;
		res.pb(a[cur]);
		vis[cur] = 1;
		res.pb(a[0]);
		vis[0] = 1;
		cur++;
		repn(i, 1, l){
			while(a[cur] == a[i]) cur++;
			res.pb(a[cur]);
			vis[i] = 1;
			res.pb(a[i]);
			vis[cur] = 1;
			cur++;
		}
		while(a[cur] == a[l - 1]) cur++;
		res.pb(a[cur]);
		vis[cur] = 1;
		rep(i, res.size()) cout << res[i] << " ";
	}
	rep(i, n) if(!vis[i]) cout << a[i] << " ";
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
