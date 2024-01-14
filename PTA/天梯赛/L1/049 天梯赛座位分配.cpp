#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//坑点：需要判断高校的最后一支队伍的上一个位置时本校的还是其他学校的
//若为本校，起点需加2，若为他校，只需要加1

vector<int> ord[105];//记录对应学校的学生最后的顺序
int num[105],n,val,last;//last记录上一个位置学生的学校
//num为对应学校的参赛学生数，val为当前学生的座号
int check() {//判断还有多少个学校还没分配
    int cnt = 0;
    for(int i = 1;i <= n;i++) if(num[i]) cnt++;
    return cnt;
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>num[i],num[i] *= 10;//学生数量需*10
    while(1) {//直到还有学生的学校数量小于等于1
        for(int i = 1;i <= n;i++) {//遍历所有学校
            if(num[i]==0) continue;//跳过没有学生的学校
            ord[i].push_back(++val);//按顺序排座号
            num[i]--;//当前学校的学生数量--
            last = i;//更新last的值，表示学校
        }
        if(check()<=1) break;//小于等于1,则停止
    }
    int index = 0;//用来记录最后一个学校的编号
    for(int i = 1;i <= n;i++) {
        if(num[i]) {//仅存一个，所以可直接退出
            index = i;break;
        }
    }
    //若还存在一个学校
    if(index) for(int i = 1;i <= num[index];i++) {//遍历剩余所有数量
        if(i==1&&last!=index) val++;//若上一个非本校学生，只需+1！！！
        else val += 2;
        ord[index].push_back(val);
    }
    for(int i = 1;i <= n;i++) {
        cout<<"#"<<i<<"\n";
        int cnt = 1;//cnt表示当前为第几列
        for(int j = 0;j < (int)ord[i].size();j++) {
            if(cnt!=1) cout<<" ";
            cout<<ord[i][j];
            if(cnt==10) cout<<"\n",cnt = 1;//隔十个一个回车
            else cnt++;
        }
    }
    return 0;
}
