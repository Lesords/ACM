#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺�����������Ƚϣ����Կ��Խ����й��ҷֳ��������䣬�ֱ�����
//Ȼ��ȡ��С��һ�����Ҽ���

const int MAXN = 1<<7+10;
struct node{
    int val,pos;
    friend bool operator < (node a,node b) {
        return a.val > b.val;//�Ӵ�С����
    }
}a[MAXN];
int main() {
    int n,len;
    cin>>n;
    len = 1<<n;
    for(int i = 1;i <= len;i++) {
        cin>>a[i].val;
        a[i].pos = i;
    }
    sort(a+1,a+len/2+1);//������
    sort(a+len/2+1,a+len+1);//������
    if(a[1].val>a[len/2+1].val) {
        cout<<a[len/2+1].pos;
    }
    else cout<<a[1].pos;
    return 0;
}
