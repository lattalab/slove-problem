// accepted
# include <iostream>
using namespace std;
# define Max 100010
int main()
{
    int n,m ,op, cases =1;
    int left[Max]; // left neighbor
    int right[Max]; // right neighbor
    while(cin >> n >> m)
    {
        left[0] = n; right[0] = 1;
        for(int i=1;i<=n;i++) // initial
        {
            left[i] = i-1;
            right[i] = (i+1) % (n+1);
        }

        bool flag = false;
        while(m--)
        {
            cin >> op;
            if (op == 4)
            {
                flag = !flag;
                continue;
            }
            else
            {
                int n1,n2, temp;
                cin >> n1 >> n2;
                if (flag) // if reverse, 1 will do 2 in original sequence
                    op = 3-op;
                else
                    op %= 3;

                switch(op)
                {
                    case 0: // swap
                    if (n1 == n2) break;
                    if (right[n1] == n2) // 數字相鄰時
                    {
                        // n1 左鄰居
                        left[n2] = left[n1];
                        right[left[n1]] = n2;
                        // n2 右鄰居
                        right[n1] = right[n2];
                        left[right[n2]] = n1;
                        // n1, n2 互接
                        right[n2] = n1;
                        left[n1] = n2;
                        break;
                    }
                    else if (left[n1] == n2) 
                    {
                        // n1 右鄰居
                        right[n2] = right[n1];
                        left[right[n1]] = n2;
                        // n2 左鄰居
                        left[n1] = left[n2];
                        right[left[n2]] = n1;
                        // n1, n2 互接
                        right[n1] = n2;
                        left[n2] = n1;
                        break;
                    }
                    else{ // 數字不相鄰
                        // n1附近鄰居
                        right[left[n1]] = n2;
                        left[right[n1]] = n2;
                        right[left[n2]] = n1;
                        left[right[n2]] = n1;
                        temp = right[n1];
                        right[n1] = right[n2];
                        right[n2] = temp;
                        temp = left[n2];
                        left[n2] = left[n1];
                        left[n1] = temp;
                    }
                    break;
                    case 1: // insert left
                    if (left[n2] == n1) break;

                        // n1 附近鄰居
                        left[right[n1]] = left[n1]; 
                        right[left[n1]] = right[n1];
                        // n1左邊
                        right[left[n2]] = n1;
                        left[n1] =left[n2];
                        // n1右邊
                        left[n2] = n1;
                        right[n1] = n2;
                    break;
                    case 2: // insert right
                    if (right[n2] == n1) break;

                        // n1附近鄰居
                        right[left[n1]] = right[n1];
                        left[right[n1]] = left[n1];
                        // n1 右邊
                        left[right[n2]] = n1;
                        right[n1] = right[n2];
                        // n1 左邊
                        left[n1] = n2;
                        right[n2] = n1; 
                        break;
                }
            }

        }

        long long int sum =0;
        bool odd = true;
        // 往右一直遞迴 , 跑完整個list
        for(int i=right[0];i; i = right[i])
        {
            if (odd)
                sum += (long long int)i;
            odd = !odd;
        }
        // 有反轉且 n是偶數要更新
        // 奇數沒反轉跟有反轉算出來一樣
        if (flag && n%2 == 0) sum = (long long int)n*(n+1)/2.0 - sum;

        cout << "Case " << cases++ << ": " << sum <<endl;
    }
    return 0;
}