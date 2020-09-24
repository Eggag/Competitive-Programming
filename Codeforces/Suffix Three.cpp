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
	rep(i, n){
		string s;
		cin >> s;
		int n1 = s.size();
		if(s.size() > 1 && s.substr(n1 - 2, 2) == "po") cout << "FILIPINO" << endl;
		if(s.size() > 3 && ((s.substr(n1 - 4, 4) == "desu") || (s.substr(n1 - 4, 4) == "masu"))) cout << "JAPANESE" << endl;
		if(s.size() > 4 && s.substr(n1 - 5, 5) == "mnida") cout << "KOREAN" << endl; 
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
