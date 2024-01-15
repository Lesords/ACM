#include<iostream>//ac
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

//题解：队列维护24小时内所有的乘客，而不是维护24小时内到达的船！！！
//然后用map记录对应国籍的出现人数，并对应修改ans

const int TIME = 86400;//24小时对应秒数
struct node{//保存到达时间和国籍
    int time,nation;
};
queue<node> q;//维护24小时范围内的所有乘客
map<int,int> num;//记录对应国籍的人数
int main() {
    int n,ans = 0;//ans用来维护当前的国籍数
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//加速
    cin>>n;
    for(int i = 1;i <= n;i++) {//n个船
        int tmp,arrive,siz;
        cin>>arrive>>siz;//到达时间和人数
        for(int j = 1;j <= siz;j++) {//当前船的所有人
            cin>>tmp,q.push(node{arrive,tmp});//所有人入队列
            if(num[tmp]==0) ans++;//如果出现新的国籍，则ans++
            num[tmp]++;//每个人的国籍都需要记录！！！
        }
        while(arrive-q.front().time>=TIME) {//去除队首超过24小时的船员
            if(--num[q.front().nation]==0) --ans;//去掉之后无此国籍的人时，ans--
            q.pop();//出队列
        }
        cout<<ans<<endl;
    }
    return 0;
}
