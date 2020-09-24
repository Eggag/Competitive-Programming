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

int prime_count(int n){
	set<int> divs;
	for(int i = 2; (i * i) <= n; i++){
		while(n % i == 0){
			n /= i;
			divs.insert(i);
		}
	}
	if(n > 1) divs.insert(n);
	return (int)divs.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int i = 1;
	while(1){
		int f = 0;
		if(prime_count(i) == 4) f++;
		if(prime_count(i + 1) == 4) f++;
		if(prime_count(i + 2) == 4) f++;
		if(prime_count(i + 3) == 4) f++;
		if(f == 4){
			cout << i << endl;
			return 0;
		}
		i++;
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
