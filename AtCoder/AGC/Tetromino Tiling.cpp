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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll lon, squ, tri, lle, lri, zri, zle;
	cin >> lon >> squ >> tri >> lle >> lri >> zri >> zle;
	ll tot1 = squ * 2;
	tot1 += 4 * (lle / 2);
	tot1 += 4 * (lri / 2);
	tot1 += (lon / 2) * 4;
	if((lon & 1) && (lle & 1) && (lri & 1)) tot1 += 6;
	ll tot2 = squ * 2;
	if(lon && lle && lri) tot2 += 6, lon--, lle--, lri--;
	tot2 += 4 * (lle / 2);
	tot2 += 4 * (lri / 2);
	tot2 += (lon / 2) * 4;
	ll tot = squ * 2;
	ll mn = min({lon, lle, lri});
	tot += mn * 6;
	lon -= mn;
	lri -= mn;
	lle -= mn;
	tot += (lon / 2) * 4;
	tot += (lle / 2) * 4;
	tot += (lri / 2) * 4;
	cout << max({tot1 / 2, tot / 2, tot2 / 2}) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
