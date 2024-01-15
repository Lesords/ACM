#include<iostream>//ac
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

//题解：利用map存储对应名字的分数
//删除一个人的分数，直接赋值为-1即可
//查询学生数量的话需要用num记录，直接查询会超时

map<string,int> score;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,num = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int op,sco;
        string name;
        cin>>op;
        if(op==1) {                                 //插入和更新分数
            cin>>name>>sco;
            //若不存在name，则num++
            if(score.find(name)==score.end()||score[name]==-1) num++;
            score[name] = sco;
            cout<<"OK\n";
        }
        else if(op==2) {                            //查询成绩
            cin>>name;
            if(score.find(name)!=score.end()) {     //找到name
                if(score[name]==-1) {               //值为-1，表示被删除了
                    cout<<"Not found\n";
                }
                else cout<<score[name]<<"\n";
            }
            else cout<<"Not found\n";
        }
        else if(op==3) {                            //删除成绩
            cin>>name;
            if(score.find(name)==score.end()) {
                cout<<"Not found\n";
            }
            else {
                if(score[name]==-1) cout<<"Not found\n";//值为-1，表示被删除了
                else {
                    num--;                          //删除成功，数量--
                    score[name] = -1;
                    cout<<"Deleted successfully\n";
                }
            }
        }
        else {
            cout<<num<<"\n";
        }
    }
    return 0;
}
