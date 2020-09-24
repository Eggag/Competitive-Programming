#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "office.h"
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
	int n = GetN();
	int a = -1, b = -1, rm = -1;
	map<array<int, 3>, int> res;
	repn(i, 1, 4) repn(j, i + 1, 4) repn(k, j + 1, 4){
		array<int, 3> ar = {i, j, k};
		sort(all(ar));
		if(isOnLine(i, j, k)){
			res[ar] = 1;
			a = i, b = j, rm = k;
			break;
		}
		else res[ar] = 2;
	}
	int c = -1, d = -1;
	vi pos;
	repn(i, 1, n + 1) if(i != a && i != b && i != rm) pos.pb(i);
	vector<pi> pr;
	for(int i = 0; i < pos.size() - (int)(pos.size() & 1); i += 2) pr.pb({pos[i], pos[i + 1]});
	if(pos.size() & 1) pr.pb({1e9, pos[pos.size() - 1]});
	int ind = 0;
	while(true){
		pi cur = pr[ind];
		int st = cur.fi, st1 = cur.se;
		if(st == 1e9){
			d = st1;
			break;
		}
		if(ind == (pr.size() - 1) && pos.size() % 2 == 0 && (c == -1 && d == -1)){
			c = st;
			d = st1;
			break;
		}
		if(st1 <= n && st <= n){
			array<int, 3> ar1 = {a, st, st1};
			sort(all(ar1));
			if(d == -1 && ind == (int)(pr.size() - 1) && pos.size() % 2 == 0){
				array<int, 3> ar2 = {a, st1, b};
				sort(all(ar2));
				if(res[ar2] != 1 && (res[ar2] == 2 || !isOnLine(a, b, st1))){
					if(c == -1) c = st1;
					else if(d == -1) d = st1;
				}
				else{
					if(c == -1) c = st;
					else if(d == -1) d = st;
				}
			}
			else if(res[ar1] != 1 && (res[ar1] == 2 || !isOnLine(a, st, st1))){
				array<int, 3> ar2 = {a, st, b};
				sort(all(ar2));
				if(res[ar2] != 1 && (res[ar2] == 2 || !isOnLine(a, b, st))){
					if(c == -1) c = st;
					else if(d == -1) d = st;
				}
				if(c != -1 && d != -1) break;
				ar2 = {a, st1, b};
				sort(all(ar2));
				if(res[ar2] != 1 && (res[ar2] == 2 || !isOnLine(a, b, st1))){
					if(c == -1) c = st1;
					else if(d == -1) d = st1;
				}
			}
		}
		else if(st1 > n && st <= n){
			array<int, 3> ar2 = {a, st, b};
			sort(all(ar2));
			if(res[ar2] != 1 && (res[ar2] == 2 || !isOnLine(a, b, st))){
				if(c == -1) c = st;
				else if(d == -1) d = st;
			}
		}
		else if(st1 <= n && st > n){
			array<int, 3> ar2 = {a, st1, b};
			sort(all(ar2));
			if(res[ar2] != 1 && (res[ar2] == 2 || !isOnLine(a, b, st1))){
				if(c == -1) c = st1;
				else if(d == -1) d = st1;
			}
		}
		if(st > n && st1 > n) break;
		if(c != -1 && d != -1) break;
		ind++;
	}
	Answer(a, b, c, d);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
