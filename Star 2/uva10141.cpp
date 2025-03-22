// accepted
# include <iostream>
# include <algorithm>
using namespace std;
struct manufacturer
{
    int id;
    string name;
    double price;
    int offer;
};
bool cmp(manufacturer &a , manufacturer &b)
{
    if (a.offer == b.offer && a.price == b.price)
        return a.id < b.id;
    if (a.offer == b.offer)
        return a.price < b.price;

    return a.offer > b.offer;
}
int main()
{
    int n, p , cases =1;
    bool flag = false;
    while(cin >> n >> p && (n && p))
    {
        if (flag)
            cout << endl;
        getchar(); // read newline
        string s;
        for(int i=0;i<n;i++) // request item
            getline(cin , s);

        manufacturer arr[p]; 
        for(int i=0;i<p;i++)
        {
            arr[i].id = i;
            getline(cin , arr[i].name);
            cin >> arr[i].price;
            cin >> arr[i].offer;

            getchar(); // read newline
            // item that manufacturer can offer
            for(int j=0;j<arr[i].offer;j++) 
                getline(cin , s);
        }

        sort(arr,arr+p, cmp);
        cout << "RFP #" << cases++ << endl;
        cout << arr[0].name << endl;
        flag = true;
    }
    return 0;
}