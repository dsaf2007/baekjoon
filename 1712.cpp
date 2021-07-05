#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	double A, B, C;
	std::cin >> A >> B >> C;

	int num = 1;
	
	if (ceil(A / (C - B)) >= A / (C - B))
		num = ceil(A / (C - B));
	else
		num = ceil(A / (C - B)) + 1;
	
	if (B >= C)
	{
		std::cout << -1;
		return 0;
	}
	std::cout << num;
	return 0;
}