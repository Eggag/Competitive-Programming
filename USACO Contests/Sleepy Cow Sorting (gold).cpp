#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

template<class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	int n;
	cin >> n;
	vi p(n);
	rep(i, n) cin >> p[i];
	//find the length of the 'good' suffix
	int ans = n - 1;
	ordered_set<int> b;
	b.insert(p[n - 1]); //what we will build around
	int mx = p[n - 1];
	for(int i = n - 2; i >= 0; i--){
		if(p[i] < p[i + 1]){
			b.insert(p[i]);
			mx = max(mx, p[i]);
			ans--;
		}
		else break;
	}
	//use binary search to make it faster
	vi act;
	int ind = 0;
	while(ans--){
		int num = b.order_of_key(*b.lb(p[ind]));
		if(p[ind] > mx) num = (int)b.size();
		b.insert(p[ind]);
		act.pb(num + (n - b.size()));
		mx = max(mx, p[ind]);
		ind++;
	}
	cout << act.size() << endl;
	rep(i, act.size()) cout << act[i] << " \n"[i == ((int)act.size() - 1)];
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
