#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺����ֻ��5e5������ֱ�ӱ������ɣ�ÿ��ѡС��-1�����-2
//ֱ������������

int main() {
    int n,m,ans = 0;
    cin>>n>>m;
    while(n&&m) {//nС��m��
        if(n>m) swap(n,m);//����˳��ʹnС
        if(n>=1&&m>=2) ans++,n--,m-=2;//С��-1�����-2
        else break;//�����������������
    }
    cout<<ans;
    return 0;
}
