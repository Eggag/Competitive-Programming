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
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi s; //store the positions of singles
	repn(i, 1, n - 1) if(a[i] != a[i - 1] && a[i] != a[i + 1]) s.pb(i);
	int cur = ((int)s.size() ? 1 : 0);
	int mx = 0;
	repn(i, 1, s.size()){
		if(s[i] == (s[i - 1] + 1)) cur++;
		else{
			mx = max(mx, cur);
			cur = 1;
		}
	}
	mx = max(mx, cur);
	cout << (mx + 1) / 2 << endl;
	vi b(n); //our answer
	rep(i, n) b[i] = a[i];
	int st = 0;
	cur = 0;
	repn(i, 1, n - 1){
		if(a[i] != a[i - 1] && a[i] != a[i + 1]){
			if(!cur) st = i;
			cur++;
		}
		else if(st){
			if(a[st - 1] == a[i]){
				//all in that color
				repn(j, st, i) b[j] = a[st - 1];
			}
			else{
				//half are a[st - 1], the other half is a[i]
				repn(j, st, i){
					if(abs(j - (st - 1)) < abs(j - i)) b[j] = a[st - 1];
					else b[j] = a[i];
				}
			}
			st = 0;
			cur = 0;
		}
	}
	if(st){
		int i = n - 1;
		if(a[st - 1] == a[i]){
			//all in that color
			repn(j, st, i) b[j] = a[st - 1];
		}
		else{
			//half are a[st - 1], the other half is a[i]
			repn(j, st, i){
				if(abs(j - (st - 1)) < abs(j - i)) b[j] = a[st - 1];
				else b[j] = a[i];
			}
		}
	}
	for(int x : b) cout << x << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
