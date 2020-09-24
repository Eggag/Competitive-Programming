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

int dpS[10005], dpW[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	vi p = {c, d};
	//compute the possible amounts of sugar
	memset(dpS, 0, sizeof(dpS));
	memset(dpW, 0, sizeof(dpW));
	dpS[0] = 1;
	rep(i, 2) for(int j = 0; j <= (10000 - p[i]); j++) dpS[j + p[i]] |= dpS[j];
	dpW[0] = 1;
	p = {a, b};
	rep(i, 2) for(int j = 0; j <= (10000 - (100 * p[i])); j++) dpW[j + (100 * p[i])] |= dpW[j];
	pi best = {-1, -1};
	for(int i = 100 * a; i <= f; i += 100) if(dpW[i]){
		//we pour in this much water
		int mx = e * (i / 100); //the max amount of sugar
		for(int j = mx; j >= 0; j--) if(dpS[j]){
			if((j + i) <= f){
				if((best.fi == -1) || (best.fi * i) < (j * best.se)){
					best = mp(j, i);
				}
				break;
			}
		}
	}
	cout << best.fi + best.se << " " << best.fi << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
