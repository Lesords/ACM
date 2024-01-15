#include<iostream>//ac
#include<algorithm>
using namespace std;

//���⣺ÿ��ϵͳ��ÿ��������������С�ڵ���ǰһ���߶ȵ��ڵ�
//��⣺��ÿ��ϵͳ���������ĵ���������Ϊ  ��ǵ�����С�ڵ��ڣ�������
//�����ϵͳ��Ϊ �����������
//n^2����������dp��nlogn������Ϊ ̰��+����
//nlogn:
//��ʼ����һ��ֵ��״̬
//���ű���ʣ������Ԫ��,�ж�Ԫ���Ƿ����㵱ǰ������������������
//����������ֶ�Ӧ���飬ѡ�����ŵĿ��滻�������滻

//upper_bound��lower_bound������lower_bound�ɵ��ڵ�ǰֵ��upper_bound����

const int MAXN = 1e5+1;
int a[MAXN],up[MAXN],down[MAXN];
bool cmp(int a,int b){//��������
    return a>b;
}
int main() {
    int cnt = 0,tmp;
    while(cin>>tmp) a[++cnt] = tmp;
    //������ǵ���������
    int len_down = 1;
    down[len_down] = a[1];//��ʼ����Ϊ1����ֵΪ��ֵ
    for(int i = 2;i <= cnt;i++) {//�ӵڶ�����ʼ
        if(a[i]<=down[len_down]) down[++len_down] = a[i];//��ǰ������ǵ�����ֱ�ӽ�����
        else *upper_bound(down+1,down+len_down+1,a[i],cmp) = a[i];//�ҵ���һ��С��a[i]��ֵ��������
        //ֵ��ȿ���������������ѡ��upper_bound
        //cmp�������ǽ�down������н������
    }
    //���������������
    int len_up = 1;
    up[len_up] = a[1];//��ʼ����Ϊ1����ֵΪ��ֵ
    for(int i = 2;i <= cnt;i++) {//�ӵڶ�����ʼ
        if(a[i]>up[len_up]) up[++len_up] = a[i];//��ǰ������������ֱ�ӽ�����
        else *lower_bound(up+1,up+len_up+1,a[i]) = a[i];//�ҵ���һ�����ڵ���a[i]��ֵ��������
        //ֵ��Ȳ�������������������������ѡ��lower_bound
    }
    cout<<len_down<<"\n"<<len_up<<"\n";
    return 0;
}
