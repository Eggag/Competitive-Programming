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

int n;
string s;

bool solve(int nm){
	int sum = 0;
	rep(i, n - 1){
		int f = 0;
		if(s[i] == 'x') s[i] = (char)(nm + '0'), f = 1;
		if((i - (n % 2 == 0)) & 1){
			int nw = (int)(s[i] - '0') * 2;
			string cur = to_string(nw);
			rep(j, cur.size()) sum += (cur[j] - '0');
		}
		else sum += (int)(s[i] - '0');
		if(f) s[i] = 'x';
	}
	if(((sum * 9) % 10) == (int)(s[n - 1] - '0')) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	cin >> s;
	if(s[n - 1] == 'x'){
		int sum = 0;
		rep(i, n - 1){
			if((i - (n % 2 == 0)) & 1){
				int nm = (s[i] - '0') * 2;
				string cur = to_string(nm);
				rep(j, cur.size()) sum += (cur[j] - '0');
			}
			else sum += (s[i] - '0');
		}
		cout << (sum * 9) % 10 << endl;
	}
	else{
		int x = -1;
		rep(i, 10) if(solve(i)){
			x = i;
			break;
		}
		assert(x != -1);
		cout << (char)(x + '0') << endl;
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
