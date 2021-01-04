#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{

    int n;
    cin >> n;

    vector<int> map(n + 1, 0);
    vector<int> mem(n + 1, 0);

    for (int i = 1; i < n+1; i++)
        cin >> map[i];

    mem[1] = map[1];
    mem[2] = map[1] + map[2];
    mem[3] = max(map[1] + map[3], map[2] + map[3]);

    for (int i = 4; i < n + 1; i++)
        mem[i] = max(mem[i - 2] + map[i], mem[i - 3] + map[i - 1] + map[i]);

    cout << mem[n];
}