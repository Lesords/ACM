#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
struct node{
    string name;//名字
    int score;//分数
    friend bool operator < (node a,node b) {
        //先成绩降序，然后名字升序
        if(a.score!=b.score) return a.score > b.score;
        return a.name < b.name;
    }
}a[MAXN];
int main() {
    int n,g,k,ans = 0;//ans为代金券总和的值
    cin>>n>>g>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].name>>a[i].score;
        if(a[i].score>=g) ans += 50;
        else if(a[i].score>=60) ans += 20;
    }
    sort(a+1,a+n+1);
    cout<<ans<<"\n";
    int pos = 0,last = 0;//pos表示当前的位置，last表示上一次的排名
    for(int i = 1;i <= n;i++) {
        if(pos==0) {//第一个
            cout<<++pos<<" "<<a[i].name<<" "<<a[i].score<<"\n";
            last = pos;//更新last的值
        }
        else {
            ++pos;//位置都需要累加！！！
            if(a[i].score==a[i-1].score) {
                //分数相等则用last表示排名
                cout<<last<<" "<<a[i].name<<" "<<a[i].score<<"\n";
            }
            else {
                if(pos>k) break;//分数不同，且当前超过k则结束！！！
                cout<<pos<<" "<<a[i].name<<" "<<a[i].score<<"\n";
                last = pos;//更新last的值
            }
        }
    }
    return 0;
}
