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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> m >> n;
	vi p(n);
	//we can use 30 querries to find out if nth is a 0 or 1 by asking 1
	rep(i, n){
		//at most 30 querries
		cout << "1 " << endl;
		int a;
		cin >> a;
		if(!a){
			//if 1 is the answer
			exit(0);
		}
		if(a == 1) p[i] = 1; //it tells the truth
		else p[i] = 0; //it lies
	}
	//do a normal binary search
	//it works since log2(1e9) < 30
	int l = 1, r = m;
	int cnt = 0;
	while(l <= r){
		ll mid = (r + l) / 2;
		cout << mid << endl;
		bool tru = 1;
		if(!p[cnt % n]) tru = 0;
		int ans;
		cin >> ans;
		if(!ans) exit(0);
		if(ans == 1){
			if(tru){
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		else{
			if(tru){
				 r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		cnt++;
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
