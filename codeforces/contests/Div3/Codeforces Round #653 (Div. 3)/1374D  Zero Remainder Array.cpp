#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//���⣺��ʼx=0��ÿ������������
//ѡ��һ����+x,����x++��   x++
//�����ɴ˿�֪��������������x��ֵ

//��⣺����ÿ��������Ҫ���k�ı�����������%k�洢
//Ȼ���ж�ÿ������Ҫ �Ӷ��� ��Ϊk�ı���
//����x�ڼӵĹ����У�ÿ����ֻ�����һ�Σ�
//���Զ�ÿ����ͬ��a[i](�ӵ�ֵ)����Ҫ���n��k��ֵ
//��ô����ֵ���� k*(num[a[i]]-1)+a[i]
//��Ϊ��һ������Ҫ�� k��������-1

int main() {
	int t,n,k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		map<int,int> ma;
		int flag = 0,tmp;
		ll ans = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%d",&tmp);
			tmp %= k;
			if(tmp) {
				if(!flag) flag = 1;
				ma[k-tmp]++;//��¼k-tmp������
			}
		}
		if(!flag) {//�Ѿ����㣬�������
			printf("0\n");
			continue;
		}
		for(auto num:ma) {
			//ȡ���ֵ
			ans = max(ans,num.fi*1LL+(num.se-1)*1LL*k);
		}
		//ans��Ҫ���������ֵ��������֮����+1��Ϊ����
		printf("%lld\n",ans+1);
	}
	return 0;
}
