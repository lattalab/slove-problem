// accepted
# include <iostream>
using namespace std;
int main()
{
    int n, Case=1;
    cin >> n;
    while(n--)
    {
        int x1,x2,y1,y2, count=0;
        cin >> x1 >> y1 >> x2 >> y2;
        // 每條線都是x+y
        while(x1 !=0) // 將第一個座標點移到x1 =0
        {
            x1-=1;
            y1+=1;
            count -=1; // 總距離會少算這樣
        }
        while(x2 !=0) // 將第二個座標點移到x2 =0
        {
            x2-=1;
            y2+=1;
            count+=1; // 總距離會多算這樣
        }
        while(y1 !=y2) // 最後線跟線的距離 (y1+1)
        {
            count += y1+1;
            y1++;
        }
        cout << "Case " << Case++ << ": " << count << endl;
    }
    return 0;
}