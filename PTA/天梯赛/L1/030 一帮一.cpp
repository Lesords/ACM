#include<iostream>//ac
#include<string>
using namespace std;
struct person{
    string name;
    int num;//��¼����
}boy[50],girl[50];
int main() {
    int n,a = 1,b = 1;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int sex;
        string name;
        cin>>sex>>name;
        if(sex==0) girl[b].name = name,girl[b++].num = i;//Ů
        else boy[a].name = name,boy[a++].num = i;//��
    }
    int lasta = n/2,lastb = n/2;//�յ㶼Ϊһ��
    a = b = 1;//ȫ����Ϊ���
    for(int i = 1;i <= n/2;i++) {//ֻ��һ��
        if(girl[b].num<boy[a].num) {//Ů�����θ���ǰ�������Ů��
            cout<<girl[b++].name<<" "<<boy[lasta--].name<<"\n";//�еĿ����
        }
        else {
            cout<<boy[a++].name<<" "<<girl[lastb--].name<<"\n";
        }
    }
    return 0;
}
