#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

int h, m;
int op[10];

bool check(int a, int b){
	int d, d1, d2, d3;
	if(a < 10) d = 0, d1 = a;
	else{
		d1 = a % 10;
		d = (a / 10) % 10;
	}
	if(b < 10) d2 = 0, d3 = b;
	else{
		d3 = b % 10;
		d2 = (b / 10) % 10;
	}
	if(!~op[d] || !~op[d1] || !~op[d2] || !~op[d3]) return 0;	
	int x = op[d3] * 10 + op[d2];
	int y = op[d1] * 10 + op[d];
	if(x < h && y < m){
		cout << (a < 10 ? "0" : "") << a << ":" << (b < 10 ? "0" : "") << b << '\n';	
		return 1;
	}
	return 0;
}

void solve(){
	cin >> h >> m;
	string s;
	cin >> s;
	int a = (int)(s[0] - '0') * 10 + (int)(s[1] - '0');
	int b = (int)(s[3] - '0') * 10 + (int)(s[4] - '0');
	while(a < h){
		while(b < m){
			if(check(a, b)) goto en;
			b++;
		}
		a++;
		b = 0;
	}
	cout << "00:00" << '\n';
	en:;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	memset(op, -1, sizeof(op));
	op[0] = 0;
	op[1] = 1;
	op[5] = 2;
	op[2] = 5;
	op[8] = 8;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
