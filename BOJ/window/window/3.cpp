//#include <iostream>
//#include <cstring>
//#include <cctype>
//
//using namespace std;
//int compute(int n)
//{
//	return 123;
//}
//
//int main()
//{
//	char input[100] = {};
//	gets_s(input);
//	int n, x[100] = {}, cnt = 0, num[100] = {}, i, j;
//	int index = 0, tmp;
//	//cout << strlen(input) << endl;
//	for (i = 0; i < strlen(input); i++)
//	{
//		if (isdigit(input[i]))
//		{
//			tmp = input[i] - '0';
//			//cout << input[i];
//			num[index++] = tmp;
//			if (x[tmp] == 0) //���������
//			{
//				x[tmp] = compute(tmp);
//				cnt++;
//			}
//		}
//	}
//	for (i= 0; i < index; i++)
//	{
//		cout << x[num[i]] << " ";
//	}
//	return 0;
//}


#include <iostream>
#include <cstring>
#include <cctype>
//#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int compute(int n);

int main() {
	// [!!����!!] compute �Լ��� �̹� �����Ǿ�������, ����ó���Ǿ� �ֽ��ϴ�. ȣ���ؼ� �׽�Ʈ ���ּ���.
	int x[30] = {}, i, num[30] = {}, index = 0;
	char input[100] = {};
	gets_s(input);
	for (i = 0; i < (int)strlen(input); i++)
	{
		if (isdigit(input[i]))
		{
			x[index++] = input[i] - '0';
		}
	}

	for (i = 0; i < index; i++)
	{
		if (num[x[i]] == 0)
		{
			num[x[i]] = compute(x[i]);
		}
	}
	for (i = 0; i < index; i++)
	{
		cout << num[x[i]] << " ";
	}
	return 0;
}