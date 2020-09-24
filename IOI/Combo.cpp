#include <bits/stdc++.h>
#include "combo.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

string guess_sequence(int N){
	string p = "";
	if(press("AB")){
		if(press("A")) p = "A";
		else p = "B";
	}
	else{
		if(press("X")) p = "X";
		else p = "Y";
	}
	if(N == 1) return p;
	string s = "";
	for(char c : "ABXY"){
		if(p[0] != c) s += c;
	}
	for(int i = 1; i < N - 1; i++){
		int c = press(p + s[0] + s[0] + p + s[0] + s[1] + p + s[0] + s[2] + p + s[1]);
		if(c == i + 2) p += s[0];
		if(c == i + 1) p += s[1];
		if(c == i) p += s[2];
	}
	if(press(p + s[0]) == N) p += s[0];
	else if(press(p + s[1]) == N) p += s[1];
	else p += s[2];
	return p;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
