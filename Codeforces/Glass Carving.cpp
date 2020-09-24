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

class cmp{
public:
	bool operator() (ll a, ll b){
		return a > b;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll w, h, n;
	cin >> w >> h >> n;
	swap(w, h);
	multiset<ll, cmp> vert, hor; //the lengths of the segments
	vert.insert(h), hor.insert(w);
	set<ll> vertPos, horPos; //the locations of the cuts
	vertPos.insert(0);
	vertPos.insert(h);
	horPos.insert(0);
	horPos.insert(w);
	rep(i, n){
		char c;
		ll num;
		cin >> c >> num;
		if(c == 'H'){
			auto ptr = horPos.lb(num);
			auto ptr1 = ptr;
			ptr1--;
			ll a = *ptr, b = *ptr1;
			swap(a, b);
			horPos.insert(num);
			hor.erase(hor.find(b - a));
			hor.insert(b - num);
			hor.insert(num - a);
		}
		else{
			auto ptr = vertPos.lb(num);
			auto ptr1 = ptr;
			ptr1--;
			ll a = *ptr, b = *ptr1;
			swap(a, b);
			vertPos.insert(num);
			vert.erase(vert.find(b - a));
			vert.insert(b - num);
			vert.insert(num - a);
		}
		cout << (ll)((ll)(*vert.begin()) * (ll)(*hor.begin())) << endl;
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
