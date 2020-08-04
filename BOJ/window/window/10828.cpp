//#include<iostream>
//#include<string>
//
//using namespace std;
//
//#define MAX_STACK_SIZE 10000
//
////전역 변수 선언
//int g_stack[MAX_STACK_SIZE]; //스택으로 사용할 메모리 공간
//int g_data_count = 0; //스택에 저장된 데이터의 개수
//
//
//
//void push(int a_num)
//{
//	//스택에 빈 공간이 있는 경우에만 입력을 받는다.
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