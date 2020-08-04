//#include<iostream>
//#include<string>
//
//using namespace std;
//
//#define MAX 10000
//int front = -1;
//int rear = -1;
//int queue[MAX];
//
//void push(int data)
//{
//	int tmp = (rear + 1) % MAX;
//	if (tmp != front)
//	{
//		rear = (rear + 1) % MAX;
//		queue[rear] = data;
//	}
//}
//void pop()
//{
//	if (rear==front)
//	{
//		cout << -1 <<'\n';
//	}
//	else
//	{
//		front = (front + 1) % MAX;
//		cout << queue[front] << '\n';
//	}
//}
//void size()
//{
//	cout << rear - front << '\n';
//}
//void empty()
//{
//	if (rear == front) cout << 1;
//	else cout << 0;
//	cout << '\n';
//}
//void print_front()
//{
//
//	if (rear == front)cout << -1<<'\n';
//	else cout << queue[front+1]<<'\n';
//}
//void print_back()
//{
//	if (rear == front)cout << -1<<'\n';
//	else cout << queue[rear] << '\n';
//}
//
//
//int main()
//{
//	int n, i, data;
//	string s;
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
//		else if (s == "front")
//		{
//			print_front();
//		}
//		else if (s == "back")
//		{
//			print_back();
//		}
//	}
//}