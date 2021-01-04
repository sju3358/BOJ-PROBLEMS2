#include <iostream>
#include <vector>
using namespace std;

vector<int> primenumber;


bool is_prime_num(int n)
{
    if (primenumber[n] != 0)
    {
        if (primenumber[n] == 1)
            return true;
        else
            return false;
    }
    else
    {
        if (n < 2)
        {
            primenumber[n] = -1;
            return false;
        }
        else
        {
            for (int i = 2; i*i <= n; i++)
                if (n % i == 0)
                {
                    primenumber[n] = -1;
                    return false;
                }
            primenumber[n] = 1;
            return true;
        }
    }
}

int main(void)
{
    int n;
    bool flag = false;
    cin >> n;
    primenumber.resize(n + 1);

    while (n > 1)
    {
        flag = false;

        for (int i = 2; i*i <= n; i++)
        {
            if (n % i == 0 && is_prime_num(i))
            {
                cout << i << endl;
                n = n / i;
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            cout << n;
            break;
        }
    }
}