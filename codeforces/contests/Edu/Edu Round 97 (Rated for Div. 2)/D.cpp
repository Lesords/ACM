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

//��⣺���ڸ�Ϊ1������Ϊbfs����������ǰ������϶��ǹ̶���
//�������е��Ӷ����Ǹ���������������
//��ô�ӵ������ڵ㿪ʼ�жϣ��������ǰһ���ڵ㣬��ʾΪͬһ��Ľڵ�
//����������ڵ�
//������ҪѰ���µĸ��ڵ㣨����last��¼���ڵ㣬����һλ��Ϊ�µĸ��ڵ㣩
//���ϸ�����ȣ�����h[n]��Ϊ���

const int MAXN = 2e5+5;
int a[MAXN],h[MAXN];//h[i] Ϊ i�� �ĸ߶�
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,last = 1;//lastΪ��ǰ�ĸ��ڵ�
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        h[1] = 0,h[2] = 1;//��ʼ����ǰ������ֵ�ǹ̶���
        for(int i = 3;i <= n;i++) {
            //last ���������
            //�ӽڵ�Ϊ���򣡣���
            if(a[i]<a[i-1]) last++;//��ǰֵС��ǰһ��ֵ����Ҫ�����ڵ���ӽڵ�
            h[i] = h[last] + 1;//��ǰ�ڵ�ĸ߶�Ϊ ���ڵ�+1
        }
        cout<<h[n]<<"\n";//n�ĸ߶ȼ�Ϊ���ĸ߶�
    }
	return 0;
}
