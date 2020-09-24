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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n, m;
ll a[mxN], cnt[mxN], nm[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n){
		cin >> a[i];
		if(a[i] <= 1e6) cnt[a[i]]++;
	}
	repn(i, 1, 1e6 + 1) if(cnt[i]){
		for(int j = i; j <= m; j += i){
			nm[j] += cnt[i];
		}
	}
	int mx = 0, bst = 1;
	repn(i, 1, 1e6 + 1){
		if(nm[i] > mx){
			bst = i;
			mx = nm[i];
		}
	}
	vi ans;
	rep(i, n) if(bst % a[i] == 0) ans.pb(i + 1);
	cout << bst << " " << ans.size() << endl;
	for(int x : ans) cout << x << " ";
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
