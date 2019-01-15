#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; 
	char str[300010];
	cin >> n;
	getchar();
	cin.getline(str, 300000);
	int len = strlen(str);
	char* rstart = strchr(str, 'R');
	if (!rstart) 
		rstart= &str[len];
	for (int i = rstart - str + 1; i > 0; --i) 
		cout << i << endl;
	for (char* rend; rstart && *rstart != '\0'; rstart = rend) {
		rend = strchr(rstart + 1, 'R');
		if (!rend) 
			rend = &str[len];
		for (int i = rend - str + 1; i > rstart - str + 1; --i)
			cout << i << endl;
	}
	return 0;
}