// accepted
# include <iostream>
using namespace std;
int height[10005] = {0};
int main()
{
    int l,h,r, rightest=0;
    while(scanf("%d %d %d",&l, &h, &r) != EOF)
    {
        for(int i=l; i<r;i++)
        {
            if (height[i] < h)
                height[i] = h;
            if (r > rightest)
                rightest =r;
        }
    }

    bool space = false;
    if (height[0])
    {
        cout << 0 << " " << height[0] << " ";
    }
    for(int i=1;i<=rightest;i++)
    {
        if (height[i-1] != height[i])
        {
            if (space)
                cout << " ";
            cout << i << " " << height[i];
            space = true;
        }
    }
    cout << endl;
    return 0;
}