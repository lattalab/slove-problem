// accepted
# include <iostream>
# include <stack>
# include <queue>
using namespace std;
// 模仿題目input看哪種符合
int main()
{
    int n;
    while(cin >> n)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        int command,num;
        // all set to true, because first time is not sure
        bool stack = true,queue = true,priority = true;
        for(int i=0;i<n;i++)
        {
            cin >> command >> num;
            if (command == 1) // 1 represent push
            {
                s.push(num);
                q.push(num);
                pq.push(num);
            }
            else // 2 represent pop
            {
                // Then test if the preperty is satisfy.
                // if not, we can eliminate it (set to false).
                if (stack)
                {
                    if (!s.empty() && s.top() == num) s.pop();
                    else stack = false;
                }
                if (queue)
                {
                    if (!q.empty() && q.front() == num) q.pop();
                    else queue = false;
                }
                if (priority)
                {
                    if(!pq.empty() && pq.top() == num) pq.pop();
                    else priority = false;
                }
            }
        }

        // output corresponding result
        if (!stack && !queue && !priority)  
            cout << "impossible"<<endl;
        else if (stack && !queue && !priority)
            cout << "stack" << endl;
        else if (!stack && queue && !priority)
            cout << "queue" << endl;
        else if (!stack && !queue && priority)
            cout << "priority queue" << endl;
        else
            cout << "not sure" <<endl;
    }
    return 0;
}