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
	map<int, int> m;
	vi a(n);
	rep(i, n){
		cin >> a[i], m[a[i]]++;
		if(m[a[i]] > 2){
			cout << "NO" << endl;
			return 0;
		}
	}
	sort(all(a));
	vi b = {a[0]}, c;
	vi vis(n, 0);
	vis[0] = 1;
	repn(i, 1, n){
		if(a[i] > b[b.size() - 1]){
			vis[i] = 1;
			b.pb(a[i]);
		}
	}
	for(int i = n - 1; i >= 0; i--) if(!vis[i]){
		if(!c.size() || a[i] < c[c.size() - 1]) c.pb(a[i]);
	}
	cout << "YES" << endl;
	cout << b.size() << endl;
	for(int x : b) cout << x << " ";
	cout << endl;
	cout << c.size() << endl;
	for(int x : c) cout << x << " ";
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
