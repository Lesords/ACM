#include<iostream>//ac
#include<set>
#include<string>
#include<algorithm>
using namespace std;
string s[1005];
int main() {
    int n;
    cin>>n;
    set<string> hav,mark;//hav存储有朋友的人，mark存储已输出的人
    for(int i = 1;i <= n;i++) {
        int m;cin>>m;
        for(int j = 1;j <= m;j++) cin>>s[j];
        sort(s+1,s+m+1);
        int pos = unique(s+1,s+m+1)-s;//排序后去重
        if(pos==2) continue;//如果只有一个人则跳过
        for(int j = 1;j < pos;j++) hav.insert(s[j]);//有朋友的人
    }
    cin>>n;
    int flag = 0;
    for(int i = 1;i <= n;i++) {
        string tmp;
        cin>>tmp;
        if(mark.count(tmp)) continue;//跳过已经输出的
        if(!hav.count(tmp)) {
            if(flag) cout<<" ";//处理格式
            mark.insert(tmp),cout<<tmp;
            flag = 1;
        }
    }
    if(mark.size()==0) cout<<"No one is handsome";//所有人都有朋友
    return 0;
}
