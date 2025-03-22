// accepted
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
// 算A~西元0年的leap year個數 - B~西元0年的leap year個數
char month[12][30] = {"January", "February", "March", "April", "May", "June", "July", "August", 
                            "September", "October", "November" , "December"};
int leap_year(char m[] , int d , int y, bool start)
{
    int M , leap =0;
    for(int i=0;i<12;i++) // 將字串轉成數字 (月份)
    {
        if (strcmp(m , month[i]) == 0)
            M = i+1;
    }

    if (y%4 == 0 && y%100 !=0 || y%400 ==0) // 當年是閏年
    {
        if (M ==2 && d == 29) // 如果是第一個input，會被重複算到 先扣除
        {
            if (start)
                leap--;
        }
        else if (M==1 || M==2) // 未到閏年 所以不算
            leap --;
    }

    leap += y/4 - y/100 + y/400;
    return leap;
}
int main()
{
    int t , cases =1;
    scanf("%d", &t);
    while(t--)
    {
        char m[50]; // month
        int d, y; // day and year

        scanf("%s %d, %d" , m ,&d, &y);
        int leap1 = leap_year(m,d,y, true);
        scanf("%s %d, %d" , m ,&d, &y);
        int leap2 = leap_year(m,d,y, false);

        printf("Case %d: %d\n",cases++, (leap2-leap1));
    }
    return 0;
}