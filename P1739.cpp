#include <iostream>
using namespace std;
int main() {
	char ch;
	int cnt = 0;
	while ((ch = getchar()) != '@') {
		if (ch == '(')
			++cnt;
		else if (ch == ')')
			--cnt;
		if (cnt < 0)
			break;
	}
	if (cnt)
		printf("NO");
	else
		printf("YES");
	return 0;
}