# include <iostream>
// accepted
using namespace std;
int main()
{
    int cases =1, n;
    cin >> n;
    while (n--)
    {
        int h1,m1,h2,m2;
        int H1,M1,H2,M2;
        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
        scanf("%d:%d %d:%d",&H1,&M1,&H2,&M2);
        int w1 = h1*60 + m1, w2 = h2*60 + m2;
        int cm1 = H1*60 + M1, cm2 = H2*60 + M2;
        // 中間卡到 || 老婆見面之間包會議 || 會議之間包老婆見面
        if ((cm1>=w1 && cm1<=w2)||(cm2>=w1 &&cm2<=w2) ||(cm1>=w1 &&cm2<=w2)||(cm1<=w1 &&cm2>=w2)) 
            cout << "Case " << cases++ << ": Mrs Meeting" <<endl;
        else
            cout << "Case " << cases++ << ": Hits Meeting" <<endl;
    }
    
    return 0;
}