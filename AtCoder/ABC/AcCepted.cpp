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
	if(s[0] != 'A' || s[1] == 'C' || s[(int)s.size() - 1] == 'C'){
		cout << "WA" << endl;
		return 0;
	}
	int cnt = 0;
	int f = 1;
	repn(i, 1, s.size()){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			if(s[i] == 'C'){
				cnt++;
				if(cnt > 1){
					f = 0;
					break;
				}
			}	
			else{
				f = 0;
				break;
			}
		}
	}
	if(!cnt) f = 0;
	if(f) cout << "AC" << endl;
	else cout << "WA" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
