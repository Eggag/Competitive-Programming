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
	string s;
	cin >> s;
	int h = 10 * (s[0] - '0');
	h += (s[1] - '0');
	int m = 10 * (s[3] - '0');
	m += (s[4] - '0');
	int hr = 10 * (s[1] - '0');
	hr += (s[0] - '0');
	int mr = 10 * (s[4] - '0');
	mr += (s[3] - '0');
	if(m <= hr && (!(h > 5 && h < 10)) && (!(h > 15 && h < 20))){
		//current hour
		cout << hr - m << endl;
		return 0;
	}
	int ch = 1;
	h++;
	h %= 24;
	while((h < 10 && h > 5) || (h > 15 && h < 20)){
		h++;	
		h %= 24;
		ch++;
	}
	int cur = (10 * (h % 10)) + ((h / 10));
	cout << ((60 - m) + cur) + ((ch - 1) * 60) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
