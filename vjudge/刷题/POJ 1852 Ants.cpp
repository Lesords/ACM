#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//��⣺ÿ�����������������ߣ���ʵ������һֻ����ͷ�ľ���
//���������������ߵĳ���Ϊ �����/2
//Ȼ����������ߵľ��� + �����/2 �պ�Ϊ��һֻ���ϵ���ͷ�ľ���
//�������������������൱�ڽ����ߵ�·�������ɶԷ��ߣ�

int main() {
	int t,n,m,tmp;
	scanf("%d",&t);
	while(t--) {
		int minn = 0,maxx = 0;
		scanf("%d%d",&n,&m);
		while(m--) {
			scanf("%d",&tmp);
			//minn���������϶�����ȥ�����ʱ��
			minn = max(minn,min(tmp,n-tmp));
			maxx = max(maxx,max(tmp,n-tmp));
		}
		printf("%d %d\n",minn,maxx);
	}
	return 0;
}
