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

int div(int num){
	int sum = 0;
	for(int i = 1; (i * i) <= num; i++){
		if(num % i == 0){
			if(i != num) sum += i;
			if((num / i) != i && i != 1) sum += (num / i);
		}
	}
	return sum;
}

int v[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vi p;
	memset(v, 0, sizeof(v));
	repn(i, 1, 28124){
		//first we genereate perfect numbers
		if(div(i) > i) p.pb(i), v[i] = 1;
	}	
	int sum = 0;
	repn(i, 1, 28124){
		int f = 0;
		rep(j, p.size()){
			if((i - p[j]) >= 0 && v[i - p[j]]){
				f = 1;
			}
		}
		if(!f) sum += i;
	}
	cout << sum << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
