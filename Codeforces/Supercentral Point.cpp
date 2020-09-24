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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[2005][2005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	rep(i, 2005) rep(j, 2005) g[i][j] = 0;
	vi a(n), b(n);
	rep(i, n){
		cin >> a[i] >> b[i];
		a[i] += 1000, b[i] += 1000;
		g[a[i]][b[i]] = 1;
	}
	rep(i, n){
		int f = 1;
		int ind = a[i] + 1;
		int f1 = 0;
		while(ind <= 2000){
			if(g[ind][b[i]]){
				f1 = 1;
				break;
			}
			ind++;
		}
		f &= f1;
		ind = a[i] - 1;
		f1 = 0;
		while(ind >= 0){
			if(g[ind][b[i]]){
				f1 = 1;
				break;
			}
			ind--;
		}
		f &= f1;
		ind = b[i] - 1;
		f1 = 0;
		while(ind >= 0){
			if(g[a[i]][ind]){
				f1 = 1;
				break;
			}
			ind--;
		}
		f &= f1;
		ind = b[i] + 1;
		f1 = 0;
		while(ind <= 2000){
			if(g[a[i]][ind]){
				f1 = 1;
				break;
			}
			ind++;
		}
		f &= f1;
		if(f) ans++;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
