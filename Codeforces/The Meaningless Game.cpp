#define __AVX__ 1
#define __AVX2__ 1
#define __SSE__ 1
#define __SSE2__ 1
#define __SSE2_MATH__ 1
#define __SSE3__ 1
#define __SSE4_1__ 1
#define __SSE4_2__ 1
#define __SSE_MATH__ 1
#define __SSSE3__ 1
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#include <x86intrin.h>
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

int gcd(int a, int b){
	while(b){
		int c = b;
		b = a % b;
		a = c;
	}
	return a;
}

map<pi, int> m;

void solve(int a, int b){
	int g = gcd(a, b);
	int a1 = a, b1 = b;
	if(g == 1){
		//most of the time??
		if(a == 1 && (b == 1 || b == 2)){
			putchar('Y');
			putchar('e');
			putchar('s');
			putchar('\n');
			m[mp(a1, b1)] = 1;
			m[mp(b1, a1)] = 1;
		}
		else{
			putchar('N');
			putchar('o');
			putchar('\n');
			m[mp(a1, b1)] = 2;
			m[mp(b1, a1)] = 2;
		}
		return;
	}
	vi pos;
	for(int i = 2; (i * i) <= g; i++){
		if(g % i == 0) pos.pb(i);
		while(g % i == 0){
			g /= i;
		}
	}
	if(g > 1) pos.pb(g);
	//pos has all the prime divisors of gcd(a, b)
	rep(i, pos.size()){
		if(a == 1 || b == 1) break;
		int num = 0, num1 = 0;
		while(a % pos[i] == 0 && a) a /= pos[i], num++;
		while(b % pos[i] == 0 && b) b /= pos[i], num1++;
		int f = 1;
		if((num + num1) % 3) f = 0;
		if(!num1 || !num) f = 0;
		if(num > num1) if((num - num1) > num1) f = 0;
		if(num < num1) if((num1 - num) > num) f = 0;
		if(!f){
			putchar('N');
			putchar('o');
			putchar('\n');
			m[mp(a1, b1)] = 2;
			m[mp(b1, a1)] = 2;
			return;
		}
	}
	if(a != 1 || b != 1){
		putchar('N');
		putchar('o');
		putchar('\n');
		m[mp(a1, b1)] = 2;
		m[mp(b1, a1)] = 2;
		return;
	}
	putchar('Y');
	putchar('e');
	putchar('s');
	putchar('\n');
	m[mp(a1, b1)] = 1;
	m[mp(b1, a1)] = 1;
}

int main(){
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	scanf("%d", &n);
	while(n--){
		int a, b;
		scanf("%d%d", &a, &b);
		int cur = m[mp(a, b)];
		if(cur){
			if(cur == 1){
				putchar('Y');
				putchar('e');
				putchar('s');
				putchar('\n');
			}
			else{
				putchar('N');
				putchar('o');
				putchar('\n');
			}
		}
		else solve(a, b);
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
