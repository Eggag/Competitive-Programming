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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int verSc[mxN], horSc[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	int q;
	cin >> n >> q;
	ll tot = sq(n - 2);
	set<int> ver, hor;
	ver.insert(n);
	hor.insert(n);
	rep(i, q){
		int t, r;
		cin >> t >> r;
		if(t == 1){
			if(*ver.begin() > r){
				verSc[r] = *hor.begin() - 2;
				tot -= verSc[r];
			}
			else{
				auto it = ver.lb(r);
				if(it != ver.begin()) it--;
				verSc[r] = verSc[*it];
				tot -= verSc[r];
			}
			ver.insert(r);
		}
		else{
			if(*hor.begin() > r){
				horSc[r] = *ver.begin() - 2;
				tot -= horSc[r];
			}
			else{
				auto it = hor.lb(r);
				if(it != hor.begin()) it--;
				horSc[r] = horSc[*it];
				tot -= horSc[r];
			}
			hor.insert(r);
		}
	}
	cout << tot << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
