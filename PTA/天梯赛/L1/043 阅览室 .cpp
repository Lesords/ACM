#include<iostream>//ac
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3+15;
struct node{
    int shour,sminute;//��ʼ���ʱ�Ӻͷ���
}a[MAXN];

//�ӵ㣺һ��֮�ڿ��Խ�n�ε�ͬһ����

int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        memset(a,-1,sizeof(a));
        int num,hour,minute;
        char op;
        int booknum = 0,booksum = 0;
        while(cin>>num>>op) {
            scanf("%d:%d",&hour,&minute);
            if(num==0) break;
            if(op=='S') a[num].shour=hour,a[num].sminute = minute;
            else {
                if(a[num].shour==-1) continue;
                booknum++;
                booksum += (hour*60+minute)-(a[num].shour*60+a[num].sminute);
                a[num].shour = -1;
            }
        }
        if(booknum==0) {
            cout<<"0 0\n";continue;
        }
        int ans = booksum*1.0/booknum+0.5;
        cout<<booknum<<" "<<ans<<"\n";
    }
    return 0;
}
