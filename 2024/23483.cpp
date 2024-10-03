#include <iostream>
using namespace std;

int main()
{
    int ax = -1e9, ay = 1e9 - 1;
    int bx = 1e9, by = 1e9;
    int cx = -1e9, cy = -1e9;
    int dx = 1e9, dy = -1e9 + 2;

    cout << ax << ' ' << ay << '\n';
    cout << bx << ' ' << by << '\n';
    cout << cx << ' ' << cy << '\n';
    cout << dx << ' ' << dy << '\n';

    return 0;
}