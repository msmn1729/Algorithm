//#include<iostream>
//#include<string>
//
//using namespace std;
//
//#define MAX_STACK_SIZE 10000
//
////���� ���� ����
//int g_stack[MAX_STACK_SIZE]; //�������� ����� �޸� ����
//int g_data_count = 0; //���ÿ� ����� �������� ����
//
//
//
//void push(int a_num)
//{
//	//���ÿ� �� ������ �ִ� ��쿡�� �Է��� �޴´�.
//	if (g_data_count < MAX_STACK_SIZE)
//	{
//		g_stack[g_data_count] = a_num;
//		g_data_count++;
//	}
//	else
//	{
//		cout << "stack full!" << '\n';
//	}
//}
//void pop()
//{
//	if (g_data_count == 0)
//	{
//		cout << -1 << '\n';
//	}
//	else
//	{
//		cout << g_stack[g_data_count - 1] << '\n';
//		g_data_count--;
//	}
//}
//void size()
//{
//	cout << g_data_count << '\n';
//}
//void empty()
//{
//	if (g_data_count == 0) cout << 1 << '\n';
//	else cout << 0 << '\n';
//}
//void top()
//{
//	if (g_data_count == 0) cout << -1 << '\n';
//	else cout << g_stack[g_data_count - 1] << '\n';
//}
//
//int main()
//{
//	string s;
//	int n, i, j, data;
//	cin >> n;
//	while (n--)
//	{
//		cin >> s;
//		if (s == "push")
//		{
//			cin >> data;
//			push(data);
//		}
//		else if (s == "pop")
//		{
//			pop();
//		}
//		else if (s == "size")
//		{
//			size();
//		}
//		else if (s == "empty")
//		{
//			empty();
//		}
//		else if (s == "top")
//		{
//			top();
//		}
//	}
//
//}