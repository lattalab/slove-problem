// accepted
# include <iostream>
# include <string>
# include <queue>
# include <vector>
using namespace std;
struct medicine
{
    string s; // 藥名
    int freq,prior, moment; // 頻率、優先度、現在時間
};
struct cmp
{
    bool operator()(medicine &a, medicine &b){
    if (a.moment == b.moment)
        return a.prior > b.prior;

    return a.moment > b.moment;
    }
};
int main()
{
    int t;
    cin >> t; // testcase
    while(t--)
    {
        int n,k,f;
        string s;
        // 用priority queue寫法較彈性
        priority_queue <medicine, vector<medicine>, cmp> pq;
        cin >> n >> k;
        for(int i=0;i<n;i++)
        {
            cin >> s >> f;
            pq.push({s,f,i+1,f});
        }

        while(k--)
        {
            medicine temp = pq.top(); // 得到最優先的值
            pq.pop(); // 移除
            cout << temp.moment << " " << temp.s <<endl; // output
            temp.moment += temp.freq; // 改變moment(下次服用時間)
            pq.push(temp); // 放入新資料，並讓priority queue自動進行排序
        }
        
    }
    return 0;
}