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
 
vi m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vi m1 = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vi m3 = m;
vi m4 = m;
 
int a[30];
int n;
 
bool run(int pos, int mo){
	vi m2;
	if(mo == 0) m2 = m;
	else m2 = m1;
	repn(i, 1, n){
		if(pos >= 12){
			if(mo == 1){
				m2 = m;
			}
			pos %= 12;
		}
		if(a[i] != m2[pos]) return 0;
		pos++;
	}
	return 1;
}
 
bool run1(int pos){
	repn(i, 1, n){
		pos %= 36;
		if(a[i] != m3[pos]) return 0;
		pos++;
	}
	return 1;
}
 
 
bool run2(int pos){
	repn(i, 1, n){
		pos %= 36;
		if(a[i] != m4[pos]) return 0;
		pos++;
	}
	return 1;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(j, 12){
		if(a[0] == m[j]){
			if(run(j + 1, 0)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	rep(j, 12){
		if(a[0] == m1[j]){
			if(run(j + 1, 1)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	rep(i, 12) m3.pb(m1[i]);
	rep(i, 12) m3.pb(m[i]);
	rep(i, 12) m4.pb(m[i]);
	rep(i, 12) m4.pb(m1[i]);
	rep(j, 12){
		if(a[0] == m[j]){
			if(run1(j + 1)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	rep(j, 12){
		if(a[0] == m[j]){
			if(run2(j + 1)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
