#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	map<int, int> m;
	vi a(n);
	rep(i, n) cin >> a[i], m[a[i]]++;
	int cur = 0, cur1 = 0;
	int h = 0;
	for(auto x : m){
		if(x.se == 1){
			cur++;
		}
		else if(x.se != 2){ //2s are useless)))
			cur1++;	
			h = x.fi;
		}
	}
	if(cur % 2 == 0){
		cout << "YES" << endl;
		int f = 1;
		rep(i, n){
			if(m[a[i]] == 1){
				if(f){
					cout << 'B';		
				}
				else{
					cout << 'A';
				}
				f ^= 1;
			}
			else{
				cout << 'B';
			}
		}
		cout << endl;
		return 0;
	}
	if(!cur1) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		int f = 1;
		int fst = 1;
		rep(i, n){
			if(m[a[i]] == 1){
				if(f){
					cout << 'B';		
				}
				else{
					cout << 'A';
				}
				f ^= 1;
			}
			else{
				if(fst && a[i] == h) cout << 'A', fst = 0;
				else cout << 'B';
			}
		}
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
