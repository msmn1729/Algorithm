#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

vector<pair<int, string>> pv;

bool comp(const pair<int, string> &a, const pair<int, string> &b) {
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << setprecision(16);
	string s;
	int n, in;
	cin >> n;
	while (n--)
	{
		cin >> in >> s;
		pv.push_back(make_pair(in, s));
	}
	stable_sort(pv.begin(), pv.end(), comp);
	for (auto i = pv.begin(); i != pv.end(); i++)
	{
		cout << i->first << ' ' << i->second << '\n';
	}
}