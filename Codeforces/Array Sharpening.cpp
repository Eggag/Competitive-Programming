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

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	//the only problem is going below 0
	vi can(n, 0); //can we go down from here?
	for(int i = n - 1; i >= 0; i--){
		if(i == (n - 1)){
			can[i] = 1;
			continue;
		}
		if(a[i] > a[i + 1]) can[i] = 1;
		else{
			if((n - i - 1) <= a[i]){
				//we can line them up	
				can[i] = 1;
			}
			else break; //no way
		}
	}
	rep(i, n){
		if(i == 0){
			if(can[i]){
				cout << "Yes" << endl;
				return;
			}
			continue;
		}
		//check if we can get this far
		if(a[i] <= a[i - 1]){
			if(!(a[i] >= i)) break; //this is bad
		}
		if(can[i]){
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
