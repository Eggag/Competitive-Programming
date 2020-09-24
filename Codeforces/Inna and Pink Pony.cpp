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

int n, m, i, j, a, b;

bool valid(int x, int y){
	return (x >= 1 && y >= 1 && x <= n && y <= m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> i >> j >> a >> b;
	if(n == 1){
		if(!((i == 1 && j == m) || (i == 1 && j == 1))){
			cout << "Poor Inna and pony!" << endl;
		}
		else cout << 0 << endl;
		return 0;
	}
	if(m == 1){
		if(!((i == n && j == 1) || (i == 1 && j == 1))){
			cout << "Poor Inna and pony!" << endl;
		}
		else cout << 0 << endl;
		return 0;
	}
	int mn = 1e9;
	vector<pi> pos = {mp(1, 1), mp(n, 1), mp(1, m), mp(n, m)};
	rep(k, pos.size()){
		int x1 = pos[k].fi, y1 = pos[k].se;
		int x = abs(x1 - i), y = abs(y1 - j);
		if(x % a == 0 && y % b == 0){
			int nm = x / a;
			int nm1 = y / b;
			if(nm > nm1){
				if((nm - nm1) % 2 == 0){
					if(!(nm - nm1)) mn = min(mn, (nm - nm1) + nm1);
					if((nm - nm1) > 0 && (valid(x1, y1 - b) || valid(x1, y1 + b))){
						mn = min(mn, (nm - nm1) + nm1);
					}
				}
			}
			else{
				if((nm1 - nm) % 2 == 0){
					if(!(nm1 - nm)) mn = min(mn, (nm1 - nm) + nm);
					if((nm1 - nm) > 0 && (valid(x1 + a, y1) || valid(x1 - a, y1))){
						mn = min(mn, (nm1 - nm) + nm);
					}
				}
			}
		}
	}
	if(mn == 1e9) cout << "Poor Inna and pony!" << endl;
	else cout << mn << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
