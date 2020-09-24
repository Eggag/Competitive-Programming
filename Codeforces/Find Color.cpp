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

ld dist(ld x, ld y, ld x1, ld y1){
	return sqrtl(sq(x1 - x) + sq(y1 - y));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ld x, y;
	cin >> x >> y;
	if(!x || !y){
		cout << "black" << endl;
		return 0;
	}
	repn(r, 1, 2001){
		//the radius
		if(dist(0, 0, x, y) == r){
			cout << "black" << endl;
			return 0;
		}
		if(dist(0, 0, x, y) < r){
			if((x > 0) == (y > 0)){
				if(r % 2 == 1) cout << "black" << endl;
				else cout << "white" << endl;
			}
			else{
				if(r % 2 == 0) cout << "black" << endl;
				else cout << "white" << endl;
			}
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
