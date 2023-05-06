#include <iostream>


int main()
{
    int N;
    std::cin >> N;

    int* array = new int[N];

    for(int i = 0; i < N; i++)
    {
        std::cin >> array[i];
    }

    int prime = 0;
    bool isprime = true;
    for(int i = 0; i < N; i++)
    {
        isprime = true;
        for(int j = 2; j < array[i]; j++)
        {
            if( (array[i] % j) == 0)
            {
                isprime = false;
                break;
            } 
        }
        if(isprime == true && array[i] != 1)
            prime ++;
    }
    std::cout << prime <<std::endl;
    delete array;
    return 0;
}