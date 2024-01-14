#include<iostream>//ac
#include<string>
using namespace std;
struct person{
    string name;
    int num;//记录名次
}boy[50],girl[50];
int main() {
    int n,a = 1,b = 1;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int sex;
        string name;
        cin>>sex>>name;
        if(sex==0) girl[b].name = name,girl[b++].num = i;//女
        else boy[a].name = name,boy[a++].num = i;//男
    }
    int lasta = n/2,lastb = n/2;//终点都为一半
    a = b = 1;//全部置为起点
    for(int i = 1;i <= n/2;i++) {//只找一半
        if(girl[b].num<boy[a].num) {//女的名次更靠前，先输出女的
            cout<<girl[b++].name<<" "<<boy[lasta--].name<<"\n";//男的靠后的
        }
        else {
            cout<<boy[a++].name<<" "<<girl[lastb--].name<<"\n";
        }
    }
    return 0;
}
