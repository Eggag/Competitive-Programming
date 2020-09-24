#include <iostream>
using namespace std;

int main(){
	bool leap;
	int add = 99, day, current = 2;
	int months_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int months_days_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int ans = 0;
	for(int i = 0; i <= add; i++){
		int year_pa = 1901 + i;
		if (year_pa % 100 != 0){
			if (year_pa % 4 == 0) leap = true;
			else leap = false;
		}
	    	else{
			if (year_pa % 400 == 0) leap = true;
			else leap = false;
		}
		for (int start = 0; start <= 11; start++){
			day = current % 7;
			if (day == 0) ans++;
			if (leap == false) current += months_days[start];
			else current += months_days_leap[start];
		}
	}
	cout << ans << endl;
}
