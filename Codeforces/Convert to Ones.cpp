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
	int n;
	ll x, y;
	cin >> n >> x >> y;
	char prev = '9';
	string s = "";
	rep(i, n){
		char c;
		cin >> c;
		if(!(c == prev)) s += c;
		prev = c;
	}
	int sz = (int)s.size();
	if(sz == 1){
		if(s[0] == '1') cout << 0 << endl;
		else cout << y << endl;
		return 0;
	}
	if(sz == 2){
		cout << y << endl;
		return 0;
	}
	ll a = 0, b = 0;
	rep(i, sz){
		if(s[i] == '1') a++;
		else b++;
	}
	//if y * 2 > x + y
	if(x < y){
		cout << (b - 1) * x + y << endl;
	}
	else{
		cout << y * b << endl;
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
