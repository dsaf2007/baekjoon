#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int input;
	int d = 1;//����
	int k = 1;//����
	int n_sum = 0; //n������ ��
	int n_sum_next = 0; //n+1 ������ ��
	std::cin >> input; // �� �Է�

	int a = 0;//����
	int b = 0;//�и�

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

	int index = input - n_sum; //�࿡���� ��ġ

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
