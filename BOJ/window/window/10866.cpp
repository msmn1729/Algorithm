#include<iostream>
#include<string>
#include<algorithm>
#include<deque>

using namespace std;
int main()
{
	deque<int> dq;
	int n, i, data;
	string s;
	cin >> n;
	while (n--)
	{
		cin >> s;
		if (s == "push_front")
		{
			cin >> data;
			dq.push_front(data);
		}
		else if (s == "push_back")
		{
			cin >> data;
			dq.push_back(data);
		}
		else if (s == "pop_front")
		{
			if (dq.empty()) cout << "-1";
			else
			{
				cout << dq.front() ;
				dq.pop_front();

			}
			cout << '\n';
		}
		else if (s == "pop_back")
		{
			if (dq.empty()) cout << "-1";
			else
			{
				cout << dq.back();
				dq.pop_back();
			}
			cout << '\n';
		}
		else if (s == "size")
		{
			cout << dq.size();
			cout << '\n';
		}
		else if (s == "empty")
		{
			if (dq.empty())cout << 1;
			else cout << 0;
			cout << '\n';
		}
		else if (s == "front")
		{
			if (dq.empty()) cout << -1;
			else cout << dq.front();
			cout << '\n';
		}
		else if (s == "back")
		{
			if (dq.empty()) cout << -1;
			else cout << dq.back();
			cout << '\n';
		}
		
	}
}