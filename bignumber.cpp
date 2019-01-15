/* 高精度 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;

typedef vector<int>::const_iterator c_I_Iter;

int mod(int n, int divider)
{
	if (n >= 0)
		return n%divider;
	else
		return (n%divider + divider) % divider;
}

int myAtoI(const char* str, int len=-1)
{
	if (len==-1)
		len = strlen(str);
	if (len == 0)
		return 0;
	int num=0;
	if (str[0] == '-')
		return -myAtoI(str + 1, len - 1);
	for (int i = 0; i < len; i++)
	{
		if (str[i] > '9' || str[i] < '0')
			break;
		num *= 10;
		num += str[i]-'0';
	}
	return num;
}

struct bigNum
{
	vector<int> value;
	bool sig;
	bigNum() {}
	bigNum(string n);
	void carry();
	void resize();
	bool operator>(const bigNum &n)const;
	bool operator<(const bigNum &n)const;
	bool operator==(const bigNum &n)const;
	bool operator>=(const bigNum &n)const;
	bool operator<=(const bigNum &n)const;
	bool operator!=(const bigNum &n)const;

	bigNum operator+(const bigNum &n) const;
	void print();
};


int main()
{
	string a, b;
	cin >> a >> b;
	bigNum n(a);
	bigNum m(b);
	bigNum ans = m + n;
	ans.print();
	return 0;
}

bigNum::bigNum(string n)
{
	int len = n.length();
	//每个int存四位，低位开始存
	if (len < 4)
		value.push_back(myAtoI(n.c_str()));
	
	else
	{
		for (int i = len - 4; i >= 0; i -= 4)
			value.push_back(myAtoI(n.c_str()+i,4));
		int remain = len % 4;
		if (remain == 1 && n[0] == '-')//exception
		{
			sig = 0; 
			return;
		}
		else if (remain)
			value.push_back(myAtoI(n.c_str(), remain));
				
	}
	if (value.back() < 0)
	{
		value.back() = -value.back();
		sig = 0;
	}
	else
		sig = 1;
}

void bigNum::carry() //只能处理进位，不能处理退位
{
	int len = value.size() -1;
	for (int i = 0; i < len; i++)
	{
		int t = floor( value.at(i) / (float)10000);
		value.at(i + 1) += t;
		value.at(i) -= t*10000;
	}
	if (  value.at(len) >= 10000)
	{
		int t = floor(value.at(len) / (float)10000);
		value.at(len + 1) += t;
		value.at(len) -= t * 10000;
	}
}

void bigNum::resize()  //节约空间，例如 bigNum*0=0后需要压缩空间 
{
	int len = value.size();
	int i = len - 1;
	for (; i >= 0; i--)
	{
		if (value.at(i) != 0)
			break;
	}
	if (i!=len-1)
		value.resize(i + 1);
}

bool bigNum::operator>(const bigNum & n) const
{
	if (sig == 1 && n.sig == 0)
		return 1;
	else if (sig == 0 && n.sig == 1)
		return 0;
	else if (sig == 1 && n.sig == 1)
	{
		c_I_Iter iter1 = value.end(), iter2 = n.value.end();
		while (*(--iter1) == 0);
		while (*(--iter2) == 0);
		if (iter1 - value.end() > iter2-n.value.end())
			return 1;
		else if (iter1 - value.end() < iter2 - n.value.end())
			return 0;
		else
		{
			while (1)
			{
				if (*iter1 > *iter2)
					return 1;
				else if (*iter1 < *iter2)
					return 0;
				if (iter1 != value.begin())
				{
					iter1--;
					iter2--;
				}
				else
					return 0;
			}
		}
	}
	else if (sig == 0 && n.sig == 0)
	{
		c_I_Iter iter1 = value.end(), iter2 = n.value.end();
		while (*(--iter1) == 0);
		while (*(--iter2) == 0);
		if (iter1 - value.end() > iter2 - n.value.end())
			return 0;
		else if (iter1 - value.end() < iter2 - n.value.end())
			return 1;
		else
		{
			while (1)
			{
				if (*iter1 > *iter2)
					return 0;
				else if (*iter1 < *iter2)
					return 1;
				if (iter1 != value.begin())
				{
					iter1--;
					iter2--;
				}
				else
					return 0;
			}
		}
	}
	return 0;
}

bool bigNum::operator<(const bigNum & n) const
{
	if (sig == 1 && n.sig == 0)
		return 0;
	else if (sig == 0 && n.sig == 1)
		return 1;
	else if (sig == 1 && n.sig == 1)
	{
		c_I_Iter iter1 = value.end(), iter2 = n.value.end();
		while (*(--iter1) == 0);
		while (*(--iter2) == 0);
		if (iter1 - value.end() > iter2 - n.value.end())
			return 0;
		else if (iter1 - value.end() < iter2 - n.value.end())
			return 1;
		else
		{
			while (1)
			{
				if (*iter1 > *iter2)
					return 0;
				else if (*iter1 < *iter2)
					return 1;
				if (iter1 != value.begin())
				{
					iter1--;
					iter2--;
				}
				else
					return 0;
			}
		}
	}
	else if (sig == 0 && n.sig == 0)
	{
		c_I_Iter iter1 = value.end(), iter2 = n.value.end();
		while (*(--iter1) == 0);
		while (*(--iter2) == 0);
		if (iter1 - value.end() > iter2 - n.value.end())
			return 1;
		else if (iter1 - value.end() < iter2 - n.value.end())
			return 0;
		else
		{
			while (1)
			{
				if (*iter1 > *iter2)
					return 1;
				else if (*iter1 < *iter2)
					return 0;
				if (iter1 != value.begin())
				{
					iter1--;
					iter2--;
				}
				else
					return 0;
			}
		}
	}
	return 0;
}

bool bigNum::operator==(const bigNum & n) const
{
	if (sig != n.sig) 
		return 0;
	c_I_Iter iter1 = value.end(), iter2 = n.value.end();
	while (*(--iter1) == 0);
	while (*(--iter2) == 0);
	if (iter1 - value.end() != iter2 - n.value.end())
		return 0;
	while (1)
	{
		if (*iter1 != *iter2)
			return 0;
	
		if (iter1 != value.begin())
		{
			iter1--;
			iter2--;
		}
		else
			return 1;
	}
	return 0;
}

bool bigNum::operator>=(const bigNum & n) const
{
	return (*this > n ||*this == n);
}

bool bigNum::operator<=(const bigNum & n) const
{
	return (*this < n || *this == n);
}

bool bigNum::operator!=(const bigNum & n) const
{
	return !(*this == n);
}

bigNum bigNum::operator+(const bigNum &n) const
{
	bigNum result;
	int lenthis = value.size();
	int lenn = n.value.size();
	int maxlen = max(lenthis, lenn);
	result.value.resize(maxlen + 1);
	if (sig == 1 && n.sig == 1)//直接相加
	{
		result.sig = 1;
		if (lenthis >= lenn)
		{
			for (int i = 0; i < lenn; i++)
				result.value.at(i) = value.at(i) + n.value.at(i);

			for (int i = lenn; i < lenthis; i++)
				result.value.at(i) = value.at(i);
		}
		else
		{
			for (int i = 0; i < lenthis; i++)
				result.value.at(i) = value.at(i) + n.value.at(i);

			for (int i = lenthis; i < lenn; i++)
				result.value.at(i) = n.value.at(i);
		}
		result.carry();
	}
	else if (sig == 0 && n.sig == 0)//直接相加
	{
		result.sig = 0;
		if (lenthis >= lenn)
		{
			for (int i = 0; i < lenn; i++)
				result.value.at(i) = value.at(i) + n.value.at(i);

			for (int i = lenn; i < lenthis; i++)
				result.value.at(i) = value.at(i);
		}
		else
		{
			for (int i = 0; i < lenthis; i++)
				result.value.at(i) = value.at(i) + n.value.at(i);

			for (int i = lenthis; i < lenn; i++)
				result.value.at(i) = n.value.at(i);
		}
		result.carry();
	}
	else if (sig == 1 && n.sig == 0)
	{
		
	}
	return result;
}

void bigNum::print()
{
	if (!sig)
		printf("-");
	vector<int>::const_iterator iter = value.end();
	while (*(--iter) == 0)
	{
		if (iter == value.begin()) 
			break;
	}
	printf("%d", *iter);//首元不需要补0
	if (iter == value.begin())
		return;
	iter--;
	while (1)
	{
		printf("%04d", *iter);
		if (iter == value.begin())
			break;
		iter--;
	}
}
