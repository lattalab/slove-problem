// accept

# include <iostream>
# include <string.h>
using namespace std;
int main()
{
    int x,y;
    cin >> x >> y; //右上角端點
    //建立 地圖 設置全部的點為零
    int **map = (int **)calloc(x+1 , sizeof(int*));
    for (int i = 0;i<x+1;i++)
    {
        map[i] = (int*)calloc(y+1 , sizeof(int));
    }
    
    char orientation[4] = {'N','E','S','W'};
    int point_x,point_y;
    char direction;
    while(cin>>point_x && cin >> point_y && cin>>direction)
    {
        getchar(); // read '/n'
        char commmand[101];
        memset(commmand, '\0' , 101);
        cin >> commmand;

        int idx = 0;
        bool normal = 1, check=0;
        for (int i =0;i<4;i++) //知道一開始面對的位置
        {
            if (orientation[i] == direction)
            {
                idx = i;
            }
        }

        for(int i =0;i<strlen(commmand);i++)
        {
            if (commmand[i] == 'R') //右轉
            {
                idx = (idx+1)%4;
                direction = orientation[idx];
            }
            else if (commmand[i] == 'L') //左轉
            {
                idx = (idx+3)%4;
                direction = orientation[idx];
            }
            else //前進
            {
                if (map[point_x][point_y]) //代表曾經有機器人掉下去
                    {check = 1;}

                switch(direction)
                {
                    case 'N':
                        point_y+=1;
                        break;
                    case 'E':
                        point_x+=1;
                        break;
                    case 'S':
                        point_y-=1;
                        break;
                    case 'W':
                        point_x-=1;
                        break;
                }
            }

            if (point_x> x || point_x <0 || point_y > y || point_y < 0)
            {
                if (!check) //掉下去的機器人要特別註記
                {
                    normal =0;
                }

                if (point_x > x)
                    point_x -=1;

                if(point_y>y)
                    point_y -= 1;
                
                if(point_x<0)
                    point_y += 1;
    
                if(point_y<0)
                    point_y += 1;

                if (!map[point_x][point_y]) //該點第一次掉下去時，要標記可能掉下去的點
                {
                    map[point_x][point_y] = 1;
                    break;
                }
                    
            }
        }
        if (normal) // show output
        {
            cout << point_x <<" " << point_y <<" "<< direction <<endl;
        }
        else
        {
            cout << point_x <<" " << point_y <<" "<< direction << " LOST"<<endl;
        }
    }
    return 0;
}