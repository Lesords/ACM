#include<iostream>//ac
#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;

//��⣺���ִ�+ǰ׺�͵��������ж�
//������������ά��������С��ǰ׺��λ�ã����������SС��T
//ÿ���õ�ǰλ��-�������ж��Ƿ���������

//�ж���ʱ��ÿ����ֵ��ȥƽ����k�����Խ�����ת��Ϊ �Ƿ�����������0�����

const int MAXN = 1e5+5;
int n,s,t,a[MAXN];
double sum[MAXN];//double������
bool judge(double val) {
    deque<int> d;//��������
    for(int i = 1;i <= n;i++) {//ǰ׺�ͣ�ע���ƽ��ֵval
        sum[i] = sum[i-1] + (double)a[i]-val;
    }
    for(int i = s;i <= n;i++) {//��С�ķ�Χ��s�����Դ�s��ʼ
        if(i>=s) {//������̷�Χʱ
            //��β���ȵ�ǰֵ�������
            while(!d.empty()&&sum[d.back()]>sum[i-s]) d.pop_back();
            d.push_back(i-s);//��ǰ��ӣ�������СΪs�����Լ�s��
        }
        //�ж϶����Ƿ񳬹�t�������ĳ���
        while(!d.empty()&&i-d.front()>t) d.pop_front();
        //���ڶ��׵�Ϊ��Сֵ������ֱ���жϲ�ֵ�Ƿ����0����
        if(!d.empty()&&sum[i]-sum[d.front()]>=0) return true;
    }
    return false;
}
int main() {
    cin>>n>>s>>t;
    for(int i = 1;i <= n;i++) cin>>a[i];
    double l = -10000,r = 10000,ans = 0;//��ʼ��Ϊֵ�ķ�Χ
    while(r-l>=1e-5) {//������λС���������ж���λ
        double mid = (l+r)/2;
        //�����������Ƶ�mid����
        if(judge(mid)) ans = mid,l = mid;//�������������ans
        else r = mid;
    }
    printf("%.3lf",ans);
    return 0;
}
