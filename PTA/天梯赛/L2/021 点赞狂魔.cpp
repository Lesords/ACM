#include<iostream>//ac
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node{
    string name;
    int num;
    double avg;
    friend bool operator < (node a,node b) {
        //先不同标签的数量，然后是 标签出现次数的平均值
        if(a.num!=b.num) return a.num > b.num;
        return a.avg < b.avg;
    }
};
vector<node> ans;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        string tmp;
        set<int> ss;
        int num,tt;
        cin>>tmp>>num;
        for(int j = 1;j <= num;j++) {
            cin>>tt;
            ss.insert(tt);//利用set来去重
        }
        int len = ss.size();//不同标签的数量
        ans.push_back(node{tmp,len,num*1.0/len});
    }
    sort(ans.begin(),ans.end());//排序
    for(int i = 0;i < 3;i++) {
        if(i!=0) cout<<' ';
        if(i>=ans.size()) cout<<"-";//不足3人时
        else cout<<ans[i].name;
    }
    return 0;
}
