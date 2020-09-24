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
	cin >> n;
	string s;
	cin >> s;
	int r = 0, l = 0;
	int q = 0, q1 = 0;
	rep(i, n / 2){
		if(s[i] == '?') q++;
		else l += (s[i] - '0');
	}
	repn(i, n / 2, n){
		if(s[i] == '?') q1++;
		else r += (s[i] - '0');
	}
	if((q + q1) % 2 == 1){ //always one more move for Monocarp
		cout << "Monocarp" << endl;
		return 0;
	}
	if(!(q + q1)){ //no ?s
		cout << (l == r ? "Bicarp" : "Monocarp") << endl;
		return 0;
	}
	if(r > l){
		if(((r - l) % 9 == 0) && ((q - q1) / 2) == ((r - l) / 9)) cout << "Bicarp" << endl;
		else cout << "Monocarp" << endl;
	}
	else if(r < l){
		if(((l - r) % 9 == 0) && ((q1 - q) / 2) == ((l - r) / 9)) cout << "Bicarp" << endl;
		else cout << "Monocarp" << endl;
	
	}
	else{
		cout << (q == q1 ? "Bicarp" : "Monocarp") << endl;
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
