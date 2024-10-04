#include <iostream>
using namespace std;

int main()
{
    int ax = -1e9, ay = 0;
    int bx = 0, by = 1e9 - 1;
    int cx = 0, cy = -1e9;
    int dx = 1e9 - 1, dy = -2;

    cout << ax << ' ' << ay << '\n';
    cout << bx << ' ' << by << '\n';
    cout << cx << ' ' << cy << '\n';
    cout << dx << ' ' << dy << '\n';

    return 0;
}