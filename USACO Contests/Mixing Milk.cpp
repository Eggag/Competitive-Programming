#include <bits/stdc++.h>
using namespace std;

int main(){
	ofstream fout("mixmilk.out");
	ifstream fin("mixmilk.in");
	long long a, b, c, d, x, y;
	fin >> a >> b;
	fin >> c >> d;
	fin >> x >> y;
	for(int n = 0; n < 33; n++){
		if(b + d < c){
			d += b;
			b = 0;
		}
		else{
			b -= c - d;
			d = c;
		}
		if(d + y < x){
			y += d;
			d = 0;
		}
		else{
			d -= x - y;
			y = x;
		}
		if(y + b < a){
			b += y;
			y = 0;
		}
		else{
			y -= a - b;
			b = a;
		}
	}
	if(b + d < c){
		d += b;
		b = 0;
	}
	else{
		b -= c - d;
		d = c;
	}
	fout << b << endl;
	fout << d << endl;
	fout << y << endl;
}
