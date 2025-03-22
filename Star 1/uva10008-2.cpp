# include <iostream>
# include <string>
# include <cctype>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    getchar(); // 讀掉換行
    string s;
    int arr[26] ={0};
    char ch[26] ={'\0'};

    while(n--)
    {
        getline(cin,s);
        for(int i =0;i<s.length();i++)
        {
            if (isalpha(s[i]))
            {
                arr[toupper(s[i]) - 'A'] +=1;
                ch [toupper(s[i]) - 'A'] = toupper(s[i]);
            }
        }
    }

    for (int i =0;i<25;i++)
    {
        for(int j=0;j<25-i;j++)
        {
            if (arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
                char temp2 = ch[j];
                ch[j] = ch[j+1];
                ch[j+1] = temp2;
            }
        }
    }

    for(int i=0;i<26;i++)
    {
        if (arr[i] > 0)
        cout<<ch[i] << " "<<arr[i]<<endl;
    }
    return 0;
}