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
const int mxN = 5e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int prime[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi ans(n);
	ans[0] = a[0];
	unordered_set<int> facs;
	rep(i, mxN) prime[i] = 1;
	int f = 0;
	int st = 2;
	rep(i, n){
		if(!i) ans[i] = a[i];
		else{
			int nw = st;
			if(!f) nw = max(nw, a[i]);
			while(!prime[nw]) nw++;
			ans[i] = nw;
			if(f) st = nw + 1;
		}
		int cur = ans[i];
		vi proc;
		for(int j = 2; (j * j) <= cur; j++){
			int cnt = 0;
			while(cur % j == 0) cur /= j, cnt++;
			if(cnt && facs.find(j) == facs.end()){
				facs.insert(j);
				proc.pb(j);
			}
		}
		if(cur > 1){
			if(facs.find(cur) == facs.end()){
				facs.insert(cur);
				proc.pb(cur);
			}
		}
		rep(j, proc.size()){
			for(int k = proc[j]; k <= mxN; k += proc[j]) prime[k] = 0;
		}
		if(ans[i] > a[i]) f = 1;
	}
	rep(i, n) cout << ans[i] << " ";
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
