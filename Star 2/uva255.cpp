// accepted
# include <iostream>
using namespace std;
int main()
{
    int k,q, pos;
    while(cin >> k >> q >> pos)
    {
        int kx = k%8, ky=k/8;
        int qx = q%8, qy=q/8;
        int px = pos%8, py = pos/8;
        if (k == q)
        {
            cout << "Illegal state\n";
            continue;
        }
        // illgel move
        if (k == pos || q == pos)
        {
            cout << "Illegal move\n";
            continue;
        }
        if (qx != px && qy != py) // 對角線
        {
            cout << "Illegal move\n";
            continue;
        }
        // 可能到達國王位置:
        if (qx == px && px == kx) // 垂直移動
        {
            if ((k < q && py <= ky) || (k > q && py >= ky))
            {
                cout << "Illegal move\n";
                continue;
            }
        }
        if (qy == py && py == ky) // 水平移動
        {
            if ((k < q && px <= kx) || (k > q && px >= kx))
            {
                cout << "Illegal move\n";
                continue;
            }
        }
        // 不能走到皆能到達的地方 => 看國王附近
         if ((abs(px-kx)==1 && py==ky) || (px==kx && abs(py-ky)==1))
        {
            cout << "Move not allowed\n";
            continue;
        }

        // 國王的移動皆不符合allowed => stop
        if ((k == 0 && pos == 9) || (k == 7 && pos == 14) ||
        (k == 56 && pos == 49) || (k == 63 && pos == 54))
            cout << "Stop\n";
        else
            cout << "Continue\n";
    }
    return 0;
}