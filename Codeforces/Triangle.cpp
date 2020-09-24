#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl;
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
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool isright(int x, int y, int x1, int y1, int x2, int y2){
	if(x == x1 && y == y1) return 0;
	if(x2 == x1 && y2 == y1) return 0;
	if(x == x2 && y == y2) return 0;
	int d1 = sq(x - x1) + sq(y - y1);
	int d2 = sq(x1 - x2) + sq(y1 - y2);
	int d3 = sq(x - x2) + sq(y - y2);
	if(d1 + d2 == d3) return 1;
	if(d3 + d2 == d1) return 1;
	if(d1 + d3 == d2) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	if(isright(x, y, x1, y1, x2, y2)){
		cout << "RIGHT" << endl;
		return 0;
	}
	int f = 0;
	if(isright(x + 1, y, x1, y1, x2, y2)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x - 1, y, x1, y1, x2, y2)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x, y + 1, x1, y1, x2, y2)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x, y - 1, x1, y1, x2, y2)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x, y, x1 + 1, y1, x2, y2)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x, y, x1 - 1, y1, x2, y2)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x, y, x1, y1 + 1, x2, y2)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x, y, x1, y1 - 1, x2, y2)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x, y, x1, y1, x2 + 1, y2)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x, y, x1, y1, x2 - 1, y2)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x, y, x1, y1, x2, y2 + 1)) cout << "ALMOST" << endl, f = 1;
	else if(isright(x, y, x1, y1, x2, y2 - 1)) cout << "ALMOST" << endl, f = 1;
	if(!f){
		cout << "NEITHER" << endl;
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
