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
	while(n--){
		string s;
		cin >> s;
		int cnt = 0;
		rep(i, s.size()) if(s[i] == '0') cnt++;
		if(cnt == (s.size())){
			cout << "red" << endl;
			continue;
		}
		if(!cnt){
			cout << "cyan" << endl;
			continue;
		}
		int sum = 0;
		rep(i, s.size()) sum += (s[i] - '0');
		if(sum % 3 != 0){
			cout << "cyan" << endl;
			continue;
		}
		int f = 1;
		int f1 = 0;
		rep(i, s.size()){
			if(s[i] != '0' || f1){
				int num = ((s[i] - '0') * 10);
				if(num % 4 == 0 && f){
					cout << "red" << endl;
					f = 0;
					break;
				}
			}
			if(s[i] == '0' && !f1) f1 = 1;
		}
		if(f) cout << "cyan" << endl;
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
