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
const int MAXN = 200005;
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
int n;
ll a[MAXN], s[4 * MAXN];
 
void build(int id = 1, int l = 0, int r = n){
	if((r - l) < 2){
		s[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s[id] = s[id * 2] ^ s[id * 2 + 1];
}
 
ll query(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return (ll)0;
	if(x <= l && r <= y) return (ll)s[id];
	int mid = (l + r) / 2;
	return query(x, y, id * 2, l, mid) ^ query(x, y, id * 2 + 1, mid, r);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> n >> q;
	rep(i, n) cin >> a[i];
	build();
	rep(i, q){
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << query(l, r + 1) << endl;
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

