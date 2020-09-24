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
const int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int monthsLeap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool leap(int year){
	if(year % 100 == 0) return (year % 400 == 0);
	return year % 4 == 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		s = s.substr(0, (int)s.size() - 1);
		int d = (s[1] - '0') + (s[0] - '0') * 10;
		int m = (s[4] - '0') + (s[3] - '0') * 10;
		int y = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
		int cnt = 0;
		while(true){
			string tot = "";
			string d1 = to_string(d);
			reverse(all(d1));
			while((int)d1.size() != 2) d1 += '0';
			reverse(all(d1));
			string m1 = to_string(m);
			reverse(all(m1));
			while((int)m1.size() != 2) m1 += '0';
			reverse(all(m1));
			string y1 = to_string(y);
			reverse(all(y1));
			while((int)y1.size() != 4) y1 += '0';
			reverse(all(y1));
			tot += d1;
			tot += m1;
			tot += y1;
			string b = tot;
			reverse(all(b));
			if(tot == b && cnt != 0){
				cout << d1 << '.' << m1 << '.' << y1 << '.' << endl;
				break;
			}
			if(leap(y)){
				if(d == (monthsLeap[m] + 1)){
					m++;
					d = 1;
				}
				else d++;
				if(m == 13){
					m = 1;
					y++;
				}
			}
			else{
				if(d == (months[m] + 1)){
					m++;
					d = 1;
				}
				else d++;
				if(m == 13){
					m = 1;
					y++;
				}
				
			}
			cnt++;
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
