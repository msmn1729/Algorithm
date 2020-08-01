//#include <iostream>
//#include <cstring>
//using namespace std;
//int main()
//{
//	int x[6] = {};
//	int i, j, flag=0;
//	for (i = 0; i < 6; i++)
//	{
//		cin >> x[i];
//	}
//	for (i = 0; i < 5; i++)
//	{
//		if (x[i] > x[i + 1])
//		{
//			flag = 1;
//			break;
//		}
//	}
//	for (i = 0; i < 6; i++)
//	{
//		if (x[i] < 1 || x[i] > 45)
//		{
//			flag = 1;
//			break;
//		}
//		for (j = i + 1; j < 6; j++)
//		{
//			if (x[i] == x[j])
//			{
//				flag = 1;
//				break;
//			}
//		}
//	}
//	if (flag) puts("false");
//	else puts("true");
//
//}