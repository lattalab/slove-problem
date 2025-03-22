# include <iostream>
# include <cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string s;
        cin >> s;

        // ax+b = cx+d
        int a=0, b=0, c=0, d=0;
        // value to store the number see in the equation,
        // length: to show it digit number
        int value =0 , length =0;
        // neg: + or -
        // left: left equation before = occur
        // hasnum: test if x or multiple x(eg: 10x)
        bool neg = false , left = true ,hasnum = false;
        //complexity: O(n)
        for(int i=0;i<s.size();i++) // search the total equation
        {
            if (s[i] == 'x')
            {
                if (!hasnum) // x
                    value = 1;

                // remind the sign and left equation or right equation
                if (neg && left)
                    a -= value;
                else if ((!neg) && left)
                    a += value;
                else if (neg && (!left))
                    c -= value;
                else if ((!neg) && (!left))
                    c += value;

                // reset
                hasnum = false;
                value =0;
                length = 0;
            }
            else if (s[i] == '-')
            {
                // remind the sign and left equation or right equation
                if (neg && length && left)
                    b -= value;
                else if ((!neg) && length && left)
                    b += value;
                else if (neg && length && (!left))
                    d -= value;
                else if ((!neg) && length && (!left))
                    d += value;

                // reset
                neg = true;
                hasnum = false;
                value = 0;
                length = 0;
            }
            else if (s[i] == '+')
            {
            // remind the sign and left equation or right equation
                if (neg && length && left)
                    b -= value;
                else if ((!neg) && length &&left)
                    b += value;
                else if (neg && length && (!left))
                    d -= value;
                else if ((!neg) && length && (!left))
                    d += value;

            // reset
                neg = false;
                hasnum = false;
                value = 0;
                length = 0;
            }
            else if (s[i] == '=')
            {
                // end of left equation
                if (length && neg)
                    b -= value;
                else if (length && (!neg))
                    b += value;

                // reset
                left = false;
                neg = false;
                hasnum = false;
                value =0;
                length =0;
            }
            else
            {
                // get value
                hasnum = true;
                value *= 10;
                value += int(s[i] - '0');
                length ++;
            }
            //debug:
            //cout << value << " " << length << endl;
            //cout << a << " " << b << " " << c << " " << d <<endl;
        }

        // if value exists, remember to deal with
        if (length && neg)
            d -= value;
        else
            d += value;

        // output
        if ((a==c) && ((b!=d))) // eg: 0x = 4
            cout << "IMPOSSIBLE" << endl;
        else if ((a==c) && (b==d)) // eg: x+2 = x+2
            cout << "IDENTITY" << endl;
        else
        {
            double sol = floor((d-b)/double(a-c));
            if (sol == -0 || sol == 0) // special case
                cout << 0 << endl;
            else
                cout << sol << endl;
        }
    }
    return 0;
}