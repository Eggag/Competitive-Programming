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
	freopen("curryin.txt", "r", stdin);
	freopen("curryout.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	//take the higest 2 always?
	int d = 0, e = 0, f = 0;
	while(true){
		int cnt = 0;
		if(a > 0) cnt++;
		if(b > 0) cnt++;
		if(c > 0) cnt++;
		if(cnt < 2) break;
		int mn = min({a, b, c});
		if(mn == c){
			a--, b--;
			d++;
		}
		else if(mn == a){
			b--, c--;
			e++;
		}
		else{
			a--, c--;
			f++;
		}
	}
	cout << e << " " << f << " " << d << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
