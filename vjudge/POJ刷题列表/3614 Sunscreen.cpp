#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���е�ţ���ݽ�Сֵ���Ӵ�С����
//�������е�ţ�����ڵ�ǰ��ţ��˵�������������£�ѡspfֵ�ϸߵ�Ϊ���Ž�
//��Ϊ�����ţ��spfֵ��Խ��ԽС
//ע�⣺��ɹ˪��ֵ������ͬ�ģ�����

const int MAXN = 3e3+5;
struct node{
    int st,ed;
    friend bool operator < (node a,node b) {
        if(a.st!=b.st) return a.st > b.st;//�Ӵ�С����
        return a.ed > b.ed;
    }
}a[MAXN];
int num[MAXN],c,l,ans;//num�洢��Ӧ��ɹ˪ֵ������
int main() {
    cin>>c>>l;
    for(int i = 1;i <= c;i++) {
        cin>>a[i].st>>a[i].ed;
    }
    sort(a+1,a+1+c);//����
    for(int i = 1;i <= l;i++) {
        int tmp,tnum;
        cin>>tmp>>tnum;
        num[tmp] += tnum;//Ҫ���ۼӣ��������ͬ�ķ�ɹ˪������
    }
    for(int i = 1;i <= c;i++) {//���α������е�ţ
        for(int j = 1000;j >= 1;j--) {//�Ӵ�СѰ�����������ķ�ɹ˪
            if(num[j]==0) continue;//����û��ʣ��������
            if(j>=a[i].st&&j<=a[i].ed) {//���㵱ǰţ�ķ�Χ
                ans++;
                num[j]--;//����--
                break;//����Ѱ��
            }
        }
    }
    cout<<ans;
    return 0;
}
