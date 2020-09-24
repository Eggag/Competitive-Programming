#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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

int cnt[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	set<int> m2, m4;
	rep(i, n){
		cin >> a[i];
		cnt[a[i]]++;
		if(cnt[a[i]] >= 2) m2.insert(a[i]);
		if(cnt[a[i]] >= 4) m4.insert(a[i]);
	}
	int q;
	cin >> q;
	rep(i, q){
		char op;
		int num;
		cin >> op >> num;
		if(op == '+'){
			cnt[num]++;
			if(cnt[num] >= 2) m2.insert(num);
			if(cnt[num] >= 4) m4.insert(num);
			int f = 1;
			if(!m4.size()) f = 0;
			if(!f){
				cout << "NO" << endl;
				continue;
			}
			if(m4.size() < 2){
				if(m2.size() == 1){
					if(cnt[*m2.begin()] < 8) f = 0;
				}
				if(m2.size() == 2){
					auto it = m2.begin();
					auto it1 = it;
					it1++;
					if(max(cnt[*it], cnt[*it1]) < 6) f = 0;
				}
				if(!f){
					cout << "NO" << endl;
					continue;
				}
			}
			cout << "YES" << endl;
		}
		else{
			cnt[num]--;
			if(cnt[num] == 1) m2.erase(m2.find(num));
			if(cnt[num] == 3) m4.erase(m4.find(num));
			int f = 1;
			if(!m4.size()) f = 0;
			if(!f){
				cout << "NO" << endl;
				continue;
			}
			if(m4.size() < 2){
				if(m2.size() == 1){
					if(cnt[*m2.begin()] < 8) f = 0;
				}
				if(m2.size() == 2){
					auto it = m2.begin();
					auto it1 = it;
					it1++;
					if(max(cnt[*it], cnt[*it1]) < 6) f = 0;
				}
				if(!f){
					cout << "NO" << endl;
					continue;
				}
			}
			cout << "YES" << endl;
		}
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
