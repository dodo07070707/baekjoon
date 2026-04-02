#include <iostream>
using namespace std;

int main()
{
	int n;
	int cnt = 0;
	cin >> n;
	while (n--)
	{
		int num;
		bool flag = false;
		cin >> num;

		if (num == 1) 
		{
			continue;
		}

		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				flag = true;
			}
		}

		if (!flag)
		{
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}