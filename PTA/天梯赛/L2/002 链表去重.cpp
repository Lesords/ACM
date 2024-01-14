#include<iostream>//ac
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
struct node{
    //最后的结果只需要当前的地址和结果
    //下一个地址可以直接取后面一个的地址
    string name;
    int val;
};
map<string,int> data;//存储对应地址的值
map<string,string> nextt;//存储对应地址的下一个地址
set<int> st;//记录已出现的值（重复的以绝对值为判断标准）
int main() {
    string head;//表示起点
    int n;
    ios::sync_with_stdio(0);//加速读入
    cin.tie(0),cout.tie(0);
    cin>>head>>n;
    for(int i = 1;i <= n;i++) {
        string a,b;
        int val;
        cin>>a>>val>>b;
        nextt[a] = b;//记录a的下一个地址b
        data[a] = val;//记录a地址的值val
    }
    queue<node> ans,del;//ans保存去重后链表，del保存被删除的链表
    while(nextt.count(head)) {//最后一个的地址总是为-1
        //所以在此之前的所有地址都有下一个地址
        if(st.count(abs(data[head]))) {//若对应值已存在过，则删除
            del.push(node{head,data[head]});//放入对应的删除队列中
            head = nextt[head];//指向下一个地址
            continue;
        }
        st.insert(abs(data[head]));//放入当前值
        ans.push(node{head,data[head]});//结果队列保存当前 地址和值
        head = nextt[head];//指向下一个地址
    }
    while(!ans.empty()) {//输出所有数据
        cout<<ans.front().name<<" "<<ans.front().val<<" ";//当前节点信息
        ans.pop();//出队
        if(ans.size()) cout<<ans.front().name<<"\n";//若还有下一个，则输出此节点的地址
        else cout<<"-1\n";//否则为-1
    }
    while(!del.empty()) {//输出所有数据
        cout<<del.front().name<<" "<<del.front().val<<" ";//当前节点信息
        del.pop();//出队
        if(del.size()) cout<<del.front().name<<"\n";//若还有下一个，则输出此节点的地址
        else cout<<"-1\n";//否则为-1
    }
    return 0;
}
