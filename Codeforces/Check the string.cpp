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
	int f = 0;
	int a = 0, b = 0, c = 0;
	rep(i, s.size()){
		if(s[i] != 'a' && s[i] != 'b' && s[i] != 'c'){
			cout << "NO" << endl;
			return 0;
		}
		if(s[i] == 'a'){
			if(f){
				cout << "NO" << endl;
				return 0;
			}
			a++;
		}
		else if(s[i] == 'b'){
			if(!f) f = 1;
			if(f != 1){
				cout << "NO" << endl;
				return 0;
			}
			b++;
		}
		else{
			//c
			if(f == 1) f = 2;
			if(f != 2){
				cout << "NO" << endl;
				return 0;
			}
			c++;
		}
	}
	if((c == a || c == b) && a && b) cout << "YES" << endl;
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
