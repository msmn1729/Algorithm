#include<iostream>

using  namespace std;
int main()
{
	int i, j, n;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < n * 2 - i * 2 - 1; j++)
		{
			printf("*");
		}
		puts("");
	}

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < i * 2 + 1; j++)
		{
			printf("*");
		}
		if(i<n-1)puts("");
	}
	return 0;
}
