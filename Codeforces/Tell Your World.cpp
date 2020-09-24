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
	vector<ld> y(n);
	rep(i, n) cin >> y[i];
	ld slope = y[1] - y[0];
	int f = 1;
	repn(i, 2, n){
		if((y[i - 1] + slope) != y[i]){
			f = 0;
			break;
		}
	}
	if(f){
		cout << "No" << endl;
		return 0;
	}
	int prev = 1;
	vi vis(n, 0);
	vis[0] = 1, vis[1] = 1;
	repn(i, 2, n){
		if(y[i] == (y[prev] + (slope * (i - prev)))){
			vis[i] = 1;
			prev = i;
		}	
	}
	int st;
	rep(i, n){
		if(!vis[i]){
			st = i;
			break;
		}
	}
	int pos = 1;
	prev = st;
	repn(i, st + 1, n) if(!vis[i]){
		if(y[i] == (y[prev] + (slope * (i - prev)))){
			vis[i] = 1;
			prev = i;
		}
		else{
			pos = 0;
			break;
		}
	}
	if(pos){
		cout << "Yes" << endl;
		return 0;
	}
	slope = (y[2] - y[0]) / 2; //since it is over 2
	prev = 2;
	rep(i, n) vis[i] = 0;
	vis[0] = 1, vis[2] = 1;
	repn(i, 3, n){
		if(y[i] == (y[prev] + (slope * (i - prev)))){
			vis[i] = 1;
			prev = i;
		}	
	}
	pos = 1;
	prev = 1;
	repn(i, 3, n) if(!vis[i]){
		if(y[i] == (y[prev] + (slope * (i - prev)))){
			vis[i] = 1;
			prev = i;
		}
		else{
			pos = 0;
			break;
		}
	}
	if(pos){
		cout << "Yes" << endl;
		return 0;
	}
	slope = y[2] - y[1];
	prev = 2;
	rep(i, n) vis[i] = 0;
	vis[1] = 1, vis[2] = 1;
	repn(i, 3, n){
		if(y[i] == (y[prev] + (slope * (i - prev)))){
			vis[i] = 1;
			prev = i;
		}	
	}
	pos = 1;
	prev = 0;
	repn(i, 3, n) if(!vis[i]){
		if(y[i] == (y[prev] + (slope * (i - prev)))){
			vis[i] = 1;
			prev = i;
		}
		else{
			pos = 0;
			break;
		}
	}
	if(pos){
		cout << "Yes" << endl;
		return 0;
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
