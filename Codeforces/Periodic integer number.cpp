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
	vi mx(n, 0);
	int f = 1;
	if(n > s.size()){
		cout << 1;
		repn(i, 1, n) cout << 0;
		cout << endl;
		return 0;
	}
	for(int i = 0; i < (int)s.size() && i < n; i++) mx[i] = (int)(s[i] - '0');
	int alleq = 1;
	rep(i, s.size()){
		if(((int)(s[i] - '0')) != mx[i % n]) alleq = 0;
		if(((int)(s[i] - '0')) > mx[i % n]){
			f = 1;
			break;
		}
		if(((int)(s[i] - '0')) < (mx[i % n])){
			f = 0;
			break;
		}
	}
	if(s.size() % n == 0){
		if(f || alleq){
			if(mx[n - 1] == 9){
				mx[n - 1] = 0;
				int ind = n - 1;
				int f1 = 0;
				while(ind--){
					if(mx[ind] == 9){
						mx[ind] = 0;
					}
					else{
						f1 = 1;
						mx[ind]++;
						break;
					}
				}
				if(!f1){
					rep(i, n) mx[i] = 0;
					mx[0] = 1;
					rep(i, (((int)(s.size()) + n - 1) / n) + 1) rep(j, mx.size()) cout << mx[j];
					cout << endl;
					return 0;
				}
			}
			else mx[n - 1]++; //can be incremented
		}
		rep(i, (((int)(s.size()) + n - 1) / n)) rep(j, mx.size()) cout << mx[j];
		cout << endl;
	}
	else{
		rep(i, n) mx[i] = 0;
		mx[0] = 1;
		rep(i, (((int)(s.size()) + n - 1) / n)) rep(j, mx.size()) cout << mx[j];
		cout << endl;
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
