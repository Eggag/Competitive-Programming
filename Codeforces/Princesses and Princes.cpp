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

void solve(){
	int n;
	cin >> n;
	vi vs(n, 0);
	int notUsed = n;
	vi pos;
	rep(i, n){
		int k;
		cin >> k;
		int f = 0;
		rep(j, k){
			int x;
			cin >> x;
			x--;
			if(!f && !vs[x]){
				vs[x] = 1;
				notUsed--;
				f = 1;
			}
		}
		if(!f) pos.pb(i);
	}
	int ind = -1;
	rep(i, n) if(!vs[i]){
		ind = i;
		break;
	}
	if(!notUsed){
		cout << "OPTIMAL" << endl;
		return;
	}
	rep(i, pos.size()){
		cout << "IMPROVE" << endl;
		cout << pos[i] + 1 << " " << ind + 1 << endl;
		return;
	}
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
