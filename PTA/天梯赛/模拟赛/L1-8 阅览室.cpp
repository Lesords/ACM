#include<iostream>//wa
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;
struct node{
    int shour,sminute,ehour,eminute;
}a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        memset(a,-1,sizeof(a));
        int num,hour,minute;
        char op;
        while(cin>>num>>op) {
            scanf("%d:%d",&hour,&minute);
            if(num==0) break;
            if(op=='S') a[num].shour=hour,a[num].sminute = minute;
            else a[num].ehour = hour,a[num].eminute = minute;
        }
        int booknum = 0,booksum = 0;
        for(int j = 1;j <= 1000;j++) {
            if(a[j].shour!=-1&&a[j].ehour!=-1&&a[j].sminute!=-1&&a[j].eminute!=-1) {
                booknum++;
                booksum += (a[j].ehour*60+a[j].eminute)-(a[j].shour*60+a[j].sminute);
            }
        }
        if(booknum==0) {
            cout<<"0 0\n";continue;
        }
        cout<<booknum<<" "<<ceil(booksum*1.0/booknum*1.0)<<"\n";
    }
    return 0;
}
