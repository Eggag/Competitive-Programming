#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vector<string> s(8);
	rep(i, 8) cin >> s[i];	
	int w = 0, b = 0;
	rep(i, 8) rep(j, 8){
		if(s[i][j] <= 'Z'){
			s[i][j] += 'a' - 'A';	
			if(s[i][j] == 'q') w += 9;
			if(s[i][j] == 'r') w += 5;
			if(s[i][j] == 'b') w += 3;
			if(s[i][j] == 'n') w += 3;
			if(s[i][j] == 'p') w++;
		}
		else{
			if(s[i][j] == 'q') b += 9;
			if(s[i][j] == 'r') b += 5;
			if(s[i][j] == 'b') b += 3;
			if(s[i][j] == 'n') b += 3;
			if(s[i][j] == 'p') b++;
		}
	}
	if(w > b) cout << "White" << endl;
	else if(w < b) cout << "Black" << endl;
	else cout << "Draw" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
