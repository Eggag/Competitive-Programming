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
	ll a, b, f, k;
	cin >> a >> b >> f >> k;
	if(k == 1){
		if(b < f || (a - f) > b){
			cout << -1 << endl;
			return 0;
		}
	}
	else if(k == 2){
		if(b < f || (2 * (a - f)) > b){
			cout << -1 << endl;
			return 0;
		}
	}
	else{
		if((2 * f) > b || (2 * (a - f)) > b){
			cout << -1 << endl;
			return 0;
		}
	}
	ll cur = b;
	int ans = 0;
	rep(i, k){
		if(i % 2 == 0){
			//to a
			if(i == (k - 1)){
				//on last one
				if(a > cur){
					//need to refill
					cur = b - (a - f);
					ans++;
				}
				else cur -= a;
				break;
			}
			if((a + (a - f)) > cur){
				//need to refill
				cur = b - (a - f);
				ans++;
			}
			else cur -= a;
		}
		else{
			if(i == (k - 1)){
				//on last one
				if(a > cur){
					//need to refill
					cur = b - (a - f);
					ans++;
				}
				else cur -= a;
				break;
			}
			if((a + f) > cur){
				//need to refill
				cur = b - f;
				ans++;
			}
			else cur -= a;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
