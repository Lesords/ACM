#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺��Ŀ��˵���еľ��εĳ��ȶ�Ϊ2�ı�������ʵ����˵���ε���������������20
//���Կ���ֱ��ͳ�Ƹ�����С�ľ�������
//ÿ�δӴ�С��ʼѰ�����������ľ��Σ������������ɸ��¿�Ⱥ͸߶�

const int MAXN = 1e5+5;
int a[MAXN],num[30];//num�洢��Ӧ (1<<i) ���ε�����
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,w;
        cin>>n>>w;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            num[(int)log2(a[i])]++;//ͳ�ƶ�Ӧ���������
        }
        ll width = w,hei = 1;//��ʼ����ȣ�ʣ���ȣ�Ϊw���߶�Ϊ1
        for(int i = 1;i <= n;) {//��Ҫѡ��n������
            int tri = -1;//��¼ѡ��ľ�����
            for(int j = 20;j >= 0;j--) {//�Ӵ�С��ʼѰ��
                if(num[j]&&width>=(1<<j)) {//����ʣ���������ҷŵ���
                    width -= (1<<j);//�޸�ʣ����
                    tri = j;//��Ǳ��
                    break;
                }
            }
            if(tri==-1) {//Ϊ-1˵��û���ҵ����������ľ���
                hei++;//�޸ĸ߶Ⱥ͸��¿�ȣ������Ժ���Ĳ���
                width = w;
                continue;
            }
            num[tri]--;//��Ӧ����--��ÿ��������󶼻�ѡ�꣬���Բ���Ҫ��ʼ��Ϊ0
            i++;//������++
        }
        cout<<hei<<"\n";
    }
	return 0;
}
