#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int input;
	int d = 1;//공차
	int k = 1;//초항
	int n_sum = 0; //n까지의 합
	int n_sum_next = 0; //n+1 까지의 합
	std::cin >> input; // 수 입력

	int a = 0;//분자
	int b = 0;//분모

	int n = 1;
	n_sum_next = 1;

	while (1)
	{

		n_sum = n_sum_next;
		n_sum_next += n;
		if (input < n_sum_next)
			break;
		n++;
	}

	int index = input - n_sum; //행에서의 위치

	if (n % 2 == 0)
	{
		a = 1; b = n;
		for (int x = 0; x < index; x++)
		{
			a += 1;
			b -= 1;
		}
	}
	else if (n % 2 == 1)
	{
		a = n; b = 1;
		for (int x = 0; x < index; x++)
		{
			a -= 1;
			b += 1;
		}
	}
	std::cout << a << "/" << b;
	return 0;
}
