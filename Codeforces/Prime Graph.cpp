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

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool prime(int n){
	repn(i, 2, sqrt(n) + 1){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int m = n;
	while(!prime(m)) m++;
	cout << m << endl;
	m -= n;
	repn(i, 1, n + 1){
		if(i != n) cout << i << " " << i + 1 << endl;
		else cout << n << " " << 1 << endl;
	}
	vi cnt(n + 1, 0);
	int ind = 1;
	debug(m);
	while(m){
		int tmp = (ind + 2) % n;
		if(ind + 2 >= n) tmp++;
		if(!cnt[ind] && !cnt[tmp]){
			cout << ind << " " << tmp << endl;
			cnt[ind] = 1;
			cnt[tmp] = 1;
			m--;
		}
		ind++;
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
