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

int a[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> a[i][j];
	rep(bit, 15){
		vi fl; //the ones that have to take this no matter what
		vi ans(n, -1);
		rep(i, n){
			int cnt = 0;
			rep(j, m) if(a[i][j] & (1 << bit)) cnt++;	
			if(cnt == m) fl.pb(i), ans[i] = 0; //just take the first
		}
		int f1 = 1;
		if(fl.size() & 1){
			rep(i, n){
				if(ans[i] == -1){
					rep(j, m) if(!(a[i][j] & (1 << bit))){
						ans[i] = j;
						break;
					}
				}
				if(ans[i] == -1){
					f1 = 0;
					break;
				}
			}
		}
		else{
			int need = 1;
			rep(i, n) if(ans[i] == -1){
				rep(j, m){
					if(a[i][j] & (1 << bit)){
						if(need){
							ans[i] = j;
							need = 0;
							break;
						}
					}
				}
				if(ans[i] == -1){
					rep(j, m) if(!(a[i][j] & (1 << bit))){
						ans[i] = j;
						break;
					}
				}
				if(ans[i] == -1){
					f1 = 0;
					break;
				}
			}
			if(need) continue;
		}
		if(!f1) continue;
		cout << "TAK" << endl;
		for(int x : ans) cout << x + 1 << " ";
		cout << endl;
		return 0;
	}
	cout << "NIE" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
