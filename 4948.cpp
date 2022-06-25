#include <iostream>

int arr[1000];
int prime[246913];
int main()
{
	int i = 0;

	int input;

	while (1)
	{
		std::cin >> input;
		arr[i] = input;
		if (input == 0)
			break;
		i++;
	}

	prime[0] = 1;
	prime[1] = 1;

	for (int i = 2; i < 123456; i++)
	{
		for (int j = 2 * i; j <= 246912; j += i)
		{
			if (prime[j] == 0)
				prime[j] = 1;
		}
	}

	for (int j = 0; j < i; j++)
	{
		int num=0;
		for(int k = arr[j]+1; k <= arr[j]*2; k++)
		{
			if(prime[k] == 0)
				num++;
		}
		std::cout << num << "\n";
	}

	return 0;
}
