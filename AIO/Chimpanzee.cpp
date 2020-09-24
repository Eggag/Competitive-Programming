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
	freopen("chimpin.txt", "r", stdin);
	freopen("chimpout.txt", "w", stdout);
	int x, y;
	cin >> x >> y;
	if(!x && !y){
		cout << 0 << endl;
		return 0;
	}
	int mx = max(abs(x), abs(y));
	int ans = max(abs(x), abs(y));	
	ans--;
	ans *= 2;
	ans++;
	ans = sq(ans);
	int stX = mx, stY = -(mx - 1);
	int topY = mx, topX = -mx;
	int botY = -mx;
	int state = 1;
	while(true){
		ans++;
		if(stX == x && stY == y){
			cout << ans - 1 << endl;
			return 0;
		}
		if(state == 1){
			if(stY < topY) stY++;
			if(stY == topY) state = 2;
		}
		else if(state == 2){
			if(stX > topX) stX--;
			if(stX == topX) state = 3;
		}
		else if(state == 3){
			if(stY > botY) stY--;
			if(stY == botY) state = 4;
		}
		else{
			stX++;
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
