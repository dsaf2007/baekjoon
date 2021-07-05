#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int num;
	int prev = 0;
	int next= 0;
	std::cin >> num;
	int result;
	if (num == 1)
	{
		std::cout << 1;
		return 0;
	}

	for (int i = 0; ; i++)
	{
		
		if (num > prev * 6 +1 && num <= next*6 +1)
		{
			result = i;
			break;
		}
		//int temp = next;
		prev = next;
		next = next + i;
	}
	std::cout << result;
	return 0;
}