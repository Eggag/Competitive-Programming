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
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ld a, b, d, l;
	cin >> a >> b >> d >> l;
	if((l - a) > d){
		cout << "YES" << endl;
		return 0;
	}
	if(d <= l){
		if(d >= (l - a)) cout << "NO" << endl;
		return 0;
	}
	ld s = sqrt((d * d) - (l * l));
	ld slope = s / l;
	ld num = slope * (l - a);
	if(abs(num - b) <= 1e-7){
		cout << "NO" << endl;
		return 0;
	}
	if(num > b) cout << "YES" << endl;
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
