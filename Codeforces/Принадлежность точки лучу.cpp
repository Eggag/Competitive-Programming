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
	freopen("point2.in", "r", stdin);
	freopen("point2.out", "w", stdout);
	ll x, y;
	cin >> x >> y;
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x < x1 && x < x2 && x2 > x1){
		cout << "NO" << endl;
		return 0;
	}
	if(x > x1 && x > x2 && x2 < x1){
		cout << "NO" << endl;
		return 0;
	}
	if(x1 == x2){
		if((x != x1) || (y < y1 && y < y2 && y2 > y1) || (y > y1 && y > y2 && y2 < y1)){
			cout << "NO" << endl;
			return 0;
		}
	}
	//x1 - x2 / y1 - y2 == x - x1 / y - y1
	if(((x1 - x2) * (y - y1)) == ((x - x1) * (y1 - y2))){
		cout << "YES" << endl;
		return 0;
	}
	if(((x1 - x2) * (y - y2)) == ((x - x2) * (y1 - y2))){
		cout << "YES" << endl;
		return 0;
	}
	else cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
