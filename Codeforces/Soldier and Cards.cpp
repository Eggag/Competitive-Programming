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
	int k1;
	cin >> k1;
	vi a(k1);
	rep(i, k1) cin >> a[i];
	int k2;
	cin >> k2;
	vi b(k2);
	rep(i, k2) cin >> b[i];
	rep(i, 10000){
		if(a[0] > b[0]){
			int cur = a[0];
			reverse(all(a));
			a.pop_back();
			reverse(all(a));
			a.pb(b[0]);
			a.pb(cur);
			reverse(all(b));
			b.pop_back();
			reverse(all(b));
		}
		else{
			int cur = b[0];
			reverse(all(b));
			b.pop_back();
			reverse(all(b));
			b.pb(a[0]);
			b.pb(cur);
			reverse(all(a));
			a.pop_back();
			reverse(all(a));
		}
		if(!a.size()){
			cout << i + 1 << " " << 2 << endl;
			return 0;
		}
		if(!b.size()){
			cout << i + 1 << " " << 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
