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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w, K;
	cin >> h >> w >> K;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	int ans = 0;
	rep(i, 1 << h) rep(j, 1 << w){
		vector<string> s1 = s;
		rep(k, h) if(i & (1 << k)) rep(l, w) s1[k][l] = 'R';		
		rep(l, w) if(j & (1 << l)) rep(k, h) s1[k][l] = 'R';		
		int num = 0;
		rep(k, h) rep(l, w) if(s1[k][l] == '#') num++;
		if(num == K) ans++;
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
