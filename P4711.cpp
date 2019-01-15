#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


map<int, float> atom;


float weight(const char *start, const char* end) 
{
	if (start == end)
		return 0;
	else if (*start == '~')
	{
		float times = 1;
		++start;
		if (*start >= '0' && *start <= '9')
		{
			times = 0;
			while (*start >= '0' && *start <= '9') {
				times *= 10;
				times += *start - '0';
				++start;
			}
		}
		return times*weight(start, end);
	}
	else if (*start == '(')
	{
		const char* groupEnd = start;
		while (*groupEnd != ')')
			++groupEnd;
		if (*(groupEnd + 1) != '_')
			return weight(start + 1, groupEnd - 1) + weight(groupEnd + 1, end);
		float times=0;
		const char* p = groupEnd + 3;
		while(*p!='}')
		{
			times *= 10;
			times += *p-'0';
			++p;
		}
		return weight(start + 1, groupEnd)*times + weight(p + 1, end);
	}
	else if (*start >='A' && *start <= 'Z')
	{
		float atomWeight; const char* next = start + 1;
		if (*(start + 1) >= 'a' &&  *(start + 1) <= 'z')
		{
			atomWeight = atom[(*start) * 256 + *(start + 1)];
			++next;
		}
		else
			atomWeight = atom[(*start)];
		float times = 1;
		if (next == end) return atomWeight;
		if (*next == '_')
		{
			next += 2; times = 0;
			while (*next != '}')
			{
				times *= 10;
				times += *next - '0';
				++next;
			}
			++next;
		}
		return atomWeight*times + weight(next, end);
	}

	return 0;
}

int main()
{
	atom['H'] = 1;
	atom['C'] = 12;
	atom['N'] = 14;
	atom['O'] = 16;
	atom['F'] = 19;
	atom['Na'] = 23;
	atom['Mg'] = 24;
	atom['Al'] = 27;
	atom['Si'] = 28;
	atom['P'] = 31;
	atom['S'] = 32;
	atom['Cl'] = 35.5;
	atom['K'] = 39;
	atom['Ca'] = 40;
	atom['Mn'] = 55;
	atom['Fe'] = 56;
	atom['Cu'] = 64;
	atom['Zn'] = 65;
	atom['Ag'] = 108;
	atom['I'] = 127;
	atom['Ba'] = 137;
	atom['Hf'] = 178.5;
	atom['Pt'] = 195;
	atom['Au'] = 197;
	atom['Hg'] = 201;

	char formula[200];
	char *end = formula;
	while (scanf("%c", end) && *end!='\n' && *end!=EOF ) {
		++end;
	}
	*end = '\0';
	cout << weight(formula,end);
	return 0;
}