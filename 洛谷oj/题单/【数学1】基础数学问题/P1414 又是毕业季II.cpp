#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;

//��⣺�������Լ����ʵ���Ǹ������Ĺ�ͬ����
//����ֱ��ͳ���������ֵ����ӣ��ж϶�Ӧ���ӵ������Ƿ����㵱ǰ����
//�������㣬���ж���һ��ֵ��С������
//ע�⣺��һ��������n������������������ô��������С��n������Ҳ��������
//�����Ϊֻȡn�еĲ�������

const int MAXN = 1e6+6;
int num[MAXN];//��¼���ӳ��ֵĴ���
int main() {
    int n,maxx = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;cin>>tmp;
        maxx = max(maxx,tmp);//��¼���ֵ
        for(int j = 1;j <= sqrt(tmp);j++) {//����tmp�����е�����
            if(tmp%j) continue;//��Ϊ���ӣ�����
            num[j]++;//��¼��������
            if(j*j!=tmp) num[tmp/j]++;//��Ϊƽ����������һ������Ҳ��¼
        }
    }
    int pos = maxx;//�����ֵ��ʼ����Ѱ�ҷ���������ֵ
    for(int i = 1;i <= n;i++) {
        while(num[pos]<i) pos--;//pos���ֵĴ�����������������ֵ--
        cout<<pos<<"\n";//pos��Ϊ����Ҫ������
    }
    return 0;
}
