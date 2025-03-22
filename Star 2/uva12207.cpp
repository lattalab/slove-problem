// accepted
# include <iostream>
# include <deque>
using namespace std;
int main()
{
    int P,C, num, cases=1;
    char ch;
    while(cin >> P >> C && (C && P))
    {
        cout << "Case " << cases++ << ":"<< endl;
        deque<int> dq;
        for(int i=1;i<=min(P,C);i++) // select min to accelerate
            dq.emplace_back(i);

        for(int i=0;i<C;i++)
        {
            cin >> ch;
            if(ch == 'N')
            {
                cout << dq.front() <<endl;
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else
            {
                cin >> num;
                deque<int>::iterator it;
                for(it = dq.begin(); it!=dq.end(); it++)
                {
                    if (*it == num)
                    { 
                       dq.erase(it);
                       break;
                    }
                }
                dq.push_front(num);
            }
        }
    }
    return 0;
}