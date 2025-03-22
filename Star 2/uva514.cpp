// accepted
# include <iostream>
# include <vector>
# include <stack>
using namespace std;
int main()
{
    int n;
    while(cin >> n && n) // input n train
    {
        while(1) // test many time
        {
            int num;
            bool flag = false;
            vector<int> v;
            for(int i=0;i<n;i++) // get sequence
            {
                cin >> num;
                if (!num) 
                {
                    flag = true;
                    break;
                }
                v.push_back(num);
            }
            if (flag) 
            {
                cout << endl;
                break; // reinput n
            }

            stack<int> s;
            int idx = 0;
            for(int i=0;i<n;i++)
            {
                s.push(i+1);
                // stack 有東西 and 照著順序放出
                while (s.size() && s.top() == v[idx])
                {
                    s.pop();
                    idx++;
                }
            }

            if (s.size() == 0)
                cout << "Yes" <<endl;
            else
                cout << "No" << endl;
            }
    }
    return 0;
}