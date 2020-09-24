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

string a, b;
vi occ[30];

bool check(int g, int f){
	if(g == (int)b.size()){
		if(!f) return 1;
		else{
			cout << "-" << endl;
			exit(0);
		}
	}
	int n = b.size();
	vi pref(n, 1e9), suf(n, -1e9);
	int cur = 0;
	rep(i, n){
		auto it = lb(all(occ[b[i] - 'a']), cur);
		if(it == occ[b[i] - 'a'].end()) break;
		else{
			cur = *it + 1;
			pref[i] = cur - 1;
		}
	}
	cur = a.size() - 1;
	for(int i = n - 1; i >= 0; i--){
		if(!occ[b[i] - 'a'].size()) break;
		auto it = ub(all(occ[b[i] - 'a']), cur);	
		if(it == occ[b[i] - 'a'].end()) it--;
		else if(*it > cur && it != occ[b[i] - 'a'].begin()) it--;
		if(*it <= cur){
			cur = *it - 1;
			suf[i] = cur + 1;
		}
		else break;
	}
	rep(i, n - g + 1){
		int j = i + g;
		if((!i || (i && pref[i - 1] < a.size())) && (j >= n || (j < n && ((i && suf[j] > pref[i - 1]) || (!i && suf[j] >= 0))))){
			if(!f) return 1;
			else{
				if(i) cout << b.substr(0, i);
				if(j < n) cout << b.substr(j, (int)b.size() - j);
				cout << endl;
				exit(0);
			}
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> a >> b;
	rep(i, a.size()) occ[a[i] - 'a'].pb(i);
	int l = 0, r = b.size();
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid, 0)) r = mid;
		else l = mid + 1;
	}
	check(l, 1);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
