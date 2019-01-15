/* https://www.luogu.org/problemnew/show/P1051 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct stu
{
	char name[24];
	int scholarship;
	int no;
};

bool cmp(stu a, stu b)
{
	return  ( a.scholarship > b.scholarship ||(a.scholarship==b.scholarship && a.no<b.no));
}

int main()
{
	int n;
	cin >> n;
	stu *data = new stu[n];
	int avgScore, finalScore;
	char fromWesternProvince, isLeader;
	int essay,totalScholarship=0;
	for (int i = 0; i < n; i++)
	{
		data[i].scholarship = 0;
		scanf("%s %d %d %c %c %d", data[i].name, &finalScore, &avgScore,  &isLeader, &fromWesternProvince, &essay);
		if (finalScore > 80 && essay > 0) data[i].scholarship += 8000;
		if (finalScore > 85 && avgScore>80) data[i].scholarship += 4000;
		if (finalScore > 90 ) data[i].scholarship += 2000;
		if ((finalScore > 85) && (fromWesternProvince=='Y')) data[i].scholarship += 1000;
		if ((avgScore > 80) && (isLeader == 'Y')) data[i].scholarship += 850;
		totalScholarship += data[i].scholarship;
		data[i].no = i;
	}
	sort(data, data + n, cmp);
	cout << data[0].name << endl << data[0].scholarship<<endl<< totalScholarship;
	delete []data;
	return 0;
}