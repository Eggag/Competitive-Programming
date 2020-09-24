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
	ll n, k;
	cin >> n >> k;
	ll pos = ((k * (k - 1)) / 2) * 2;
	if(n > pos){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int cur = 1;
	int nxt = 2;
	int cnt = 0;
	pi prev = {-1, -1};
	while(cnt < n){
		if(cnt & 1){
			cout << prev.se << " " << prev.fi << endl;
		}
		else{
			if(nxt == (k + 1)) cur++, nxt = cur + 1;
			cout << cur << " " << nxt << endl;
			prev = {cur, nxt};
			nxt++;
		}
		cnt++;
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
