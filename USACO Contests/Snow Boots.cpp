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
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	int n, b;
	cin >> n >> b;
	vi f(n);
	rep(i, n) cin >> f[i];
	vector<pi> bt(b);
	rep(i, b) cin >> bt[i].fi >> bt[i].se;
	int st = 0;
	rep(i, b){
		int st1 = st;
		while(st1 && f[st1] > bt[i].fi) st1--;
		int cnt = 0;
		int f1 = 1;
		int lst = -1;
		repn(j, st1, n){
			if(f[j] > bt[i].fi) cnt++; //more snow than we can handle
			else{
				if(cnt >= bt[i].se){
					f1 = 0;
					break;
				} 
				cnt = 0;
				lst = j;
			}
		}
		if(lst < st) continue;
		if(cnt >= bt[i].se) f1 = 0;
		if(!f1){
			if(lst != -1) st = lst;	
		}
		else{
			cout << i << endl;
			return 0;
		}
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
