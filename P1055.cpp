
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c;char d;
	scanf("%d-%d-%d-%c", &a, &b, &c, &d);
	
	int checknum=a*(1e8)+ b*(1e5) + c, check  = 0;
	int i = 9;
	while (i) {
		check += (checknum % 10) * i;
		--i;
		checknum /= 10;
	}
	check %= 11;
	if (check == 10 && d == 'X' || (check == d - '0'))
		printf("Right");
	
	else {
		if (check<10)
			printf("%d-%d-%d-%d", a, b, c, check);
		else 
			printf("%d-%d-%d-X", a, b, c);
	}
		
	return 0;
}