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

int n, m;
int cntN = 0, cntM = 0;

bool good(string a, string b){
	//given base 7 numbers in the form of strings
	//check if their decimal forms are ok
	//and that everything is unique and all
	string s = a + b;
	sort(all(s));
	repn(i, 1, s.size()) if(s[i] == s[i - 1]) return 0;
	int n2 = 0, m2 = 0;
	int powN = 1, powM = 1;
	reverse(all(a));
	reverse(all(b));
	rep(i, a.size()) n2 += powN * (a[i] - '0'), powN *= 7;
	rep(i, b.size()) m2 += powM * (b[i] - '0'), powM *= 7;
	if(n2 <= n && m2 <= m) return 1;
	return 0;
}

int from7(string a){
	int n2 = 0, powN = 1;
	rep(i, a.size()) n2 += powN * (a[i] - '0'), powN *= 7;
	return n2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	n--, m--;
	//I would be surprised if this works
	//also
	//this is a stupid problem
	//just saying
	string pos = "0123456";
	int n1 = n, m1 = m;
	while(n1) cntN++, n1 /= 7;
	while(m1) cntM++, m1 /= 7;
	cntN = max(cntN, 1);
	cntM = max(cntM, 1);
	int ans = 0;
	map<string, int> vis;
	do{
		if((cntN + cntM) <= pos.size()){
			string a = pos.substr(0, cntN);
			string b = pos.substr(cntN, cntM);
			if(vis[a + b]) goto skip;
			vis[a + b] = 1;
			if(good(a, b)){
				ans++;
			}
		}
skip:;
		if((cntN + cntM - 1) <= pos.size()){
			string a = "0" + pos.substr(0, cntN - 1);
			string b = pos.substr(cntN - 1, cntM);
			if(vis[a + b]) goto skip1;
			vis[a + b] = 1;
			if(good(a, b)){
				ans++;
			}
			a = pos.substr(0, cntN);
			b = "0" + pos.substr(cntN, cntM - 1);
			if(vis[a + b]) goto skip1;
			vis[a + b] = 1;
			if(good(a, b)){
				ans++;
			}
		}
skip1:;
	} while(next_permutation(all(pos)));
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
