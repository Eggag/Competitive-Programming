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
	vi a(n);
	ll one = 0, two = 0;
	vi a1, a2;
	int last = 1;
	rep(i, n){
		cin >> a[i];
		if(i == (n - 1)){
			if(a[i] < 0) last = -1;
		}
		if(a[i] > 0){
			one += a[i];
			a1.pb(a[i]);
		}
		else{
			a[i] *= -1;
			two += a[i];
			a2.pb(a[i]);
		}
	}
	if(one != two){
		cout << ((one > two) ? "first" : "second") << endl;
		return 0;
	}
	if(a1.size() > a2.size()){
		int f = 1;
		rep(i, a2.size()) f &= (a1[i] == a2[i]);
		if(f){
			cout << "first" << endl;
			return 0;
		}
		rep(i, a2.size()){
			if(a1[i] > a2[i]){
				cout << "first" << endl;
				return 0;
			}
			if(a1[i] < a2[i]){
				cout << "second" << endl;
				return 0;
			}
		}
	}
	else if(a1.size() < a2.size()){
		int f = 1;
		rep(i, a1.size()) f &= (a1[i] == a2[i]);
		if(f){
			cout << "second" << endl;
			return 0;
		}
		rep(i, a1.size()){
			if(a1[i] > a2[i]){
				cout << "first" << endl;
				return 0;
			}
			if(a1[i] < a2[i]){
				cout << "second" << endl;
				return 0;
			}
		}
	}
	else{
		rep(i, a2.size()){
			if(a1[i] > a2[i]){
				cout << "first" << endl;
				return 0;
			}
			if(a1[i] < a2[i]){
				cout << "second" << endl;
				return 0;
			}
		}
		cout << ((last == 1) ? "first" : "second") << endl;
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
