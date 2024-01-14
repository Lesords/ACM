#include<iostream>//ac
#include<set>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
struct node{
    string name;
    double num;
    friend bool operator < (node a,node b) {
        return a.name < b.name;//按照名字排序
    }
}a[MAXN];
set<string> st;
int main() {
    int n;cin>>n;
    for(int i = 1;i <= n;i++) {
        string tmp;cin>>tmp;
        st.insert(tmp);//用set来保存在关注列表的用户
    }
    int m;cin>>m;
    double sum = 0;//sum计算点赞的总和
    for(int i = 1;i <= m;i++) cin>>a[i].name>>a[i].num,sum+=a[i].num;
    sort(a+1,a+m+1);//排序
    int flag = 0;//flag判断是由有悄悄关注的人
    sum /= m;//再取平均值
    for(int i = 1;i <= m;i++) {//遍历所有点赞的名单
        if(st.count(a[i].name)) continue;//跳过存在关注列表的用户
        if(a[i].num<sum) continue;//跳过低于平均值的用户
        flag = 1;//存在悄悄关注的人
        cout<<a[i].name<<"\n";//输出当前用户的名称即可
    }
    if(flag==0) cout<<"Bing Mei You\n";//没有悄悄关注的情况
    return 0;
}
