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
const int mxN = 7007;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool ex[mxN][mxN];
int ppcnt[mxN], vis[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vi proc;
	rep(i, n){
		int cnt = 0;
		rep(j, n) if(i != j){
			if((a[i] | a[j]) > a[j]){
				ex[i][j] = 1;
				cnt++;
			}
		}
		ppcnt[i] = cnt;
		if(cnt == (n - 1)){
			vis[i] = 1;
			proc.pb(i);
		}
	}
	int tot = n;
	while(proc.size()){
		/*
		rep(i, proc.size()) cout << proc[i] << " ";
		cout << endl;
		cout << "-----" << endl;
		*/
		vi proc1;
		rep(j, proc.size()){
			tot--;
			rep(i, n) if(!vis[i]){
				if(ex[i][proc[j]]) ppcnt[i]--;
				if(ppcnt[i] == (tot - 1)){
					vis[i] = 1;
					proc1.pb(i);
				}
			}
		}
		proc = proc1;
	}
	ll ans = 0LL;
	int num = 0;
	rep(i, n) if(!vis[i]) ans += b[i], num++;
	if(num < 2) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
