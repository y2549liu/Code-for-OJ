#pragma warning(disable:4996)
#include <bits/stdc++.h>
using namespace std;
#define maxn 1000001
char s1[maxn], s2[maxn];
int n[maxn];
int main()
{
	scanf("%s%s", s1, s2);
	n[0] = n[1] = 0;
	int len1 = strlen(s1), len2 = strlen(s2); //kΪ��ǰ����ص�����
	for (int i = 1, k = 0; i < len2; ++i) {
		while (k && s2[k] != s2[i])  //�����k+1λ�����ڵ�i+1λ
			k = n[k];
		n[i + 1] = (s2[k] == s2[i]) ? ++k : 0; //�����k+1λ���ڵ�i+1λ���ص������Լӣ�����Ϊ0
	}
	for (int i = 0, k = 0; i < len1; ++i) {
		while (k && s2[k] != s1[i])
			k = n[k];
		k = (s2[k] == s1[i]) ? k + 1 : 0;
		if (k == len2)
			printf("%d\n",i+1-(len2-1));
	}
	for (int i = 1; i <= len2; ++i) {
		printf("%d ", n[i]);
	}
	return 0;
}