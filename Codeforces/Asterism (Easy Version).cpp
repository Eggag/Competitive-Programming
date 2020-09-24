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

int num[6005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, p;
	cin >> n >> p;
	vi a(n);
	int mx = 0;
	rep(i, n) cin >> a[i], mx = max(mx, a[i]), num[a[i]]++;
	sort(all(a));
	vi ans;
	repn(i, max(mx - n + 1, 1), mx + 1){
		int f = 0;
		int v = 0;
		rep(j, i) v += num[j];
		rep(j, n){
			v += num[i + j];	
			if(v == p){
				f = 1;
				break;
			} 
			if(!v){
				f = 1;
				break;
			}
			v--;
		}
		if(!f) ans.pb(i);
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] << " ";
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
