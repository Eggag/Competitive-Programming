#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi v;
	int ans1 = 1;
	if(n == 1){
		cout << "1 0" << endl;
		return 0;
	}
	repn(i, 2, n + 1){
		int cur = 0;
		while(n % i == 0){
			n /= i;
			cur++;	
		}
		if(cur){
			ans1 *= i;
			v.pb(cur);
		}
	}
	sort(all(v));
	int ans2 = 0;
	rep(i, 32){
		if((1 << i) >= v[v.size() - 1]){
			ans2 += i;
			break;
		}
	}
	if(v[0] != (1 << ans2)) ans2++;
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
