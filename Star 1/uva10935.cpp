// accepted
# include <iostream>
# include <queue>
using namespace std;
int main()
{
    int n;
    queue<int> q;
    while(cin >> n && n)
    {
        for(int i=1;i<=n;i++) // 放入排推
            q.push(i);

        if (q.size() == 1) // 特殊情況 只有一個
        {
            cout << "Discarded cards:" << endl
                 << "Remaining card: " << q.front() << endl;
            q.pop();
        }
        else
        {
        cout << "Discarded cards: ";
            while(q.size() >2) // 拿掉上面,再把目前最上面放到最下面
            {
                cout << q.front() << ", ";
                q.pop();
                int num = q.front();
                q.pop();
                q.push(num);
            }
        cout << q.front() << endl;
        q.pop();
        cout << "Remaining card: " << q.front() <<endl;
        q.pop(); // 清空queue
        }
    }
    return 0;
}