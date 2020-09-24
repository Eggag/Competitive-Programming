#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin ("blist.in");
	int n, x, amax;
        fin >> n;
	int s[n], t[n], b[n];
	for(int i = 0; i < n; i++){
		fin >> s[i] >> t[i] >> b[i];
	}
	amax = 0;
	for(int i = 1; i <= 1000; i++){
		x = 0;
		for(int a = 0; a < n; a++){
			if(s[a] <= i && t[a] >= i){
				x += b[a];
			}
		}
		if(x > amax){
			amax = x;
		}
	}
	ofstream fout("blist.out");
	fout << amax << endl;
	return 0;
}
