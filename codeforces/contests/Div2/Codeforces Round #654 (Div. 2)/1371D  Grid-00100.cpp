#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define two(x) (x)*(x)
using namespace std;
int map[303][303],r[303],c[303];
int main() {
	int t,n,k;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		int num = 0;
		memset(map,0,sizeof(map));
		//���Խ�������k��1���Խ��������ƶ���
		for(int i = 1;i <= n&&num!=k;i++) {
			int x = 1,y = i;//��һ�����Ǵӵ�һ�п�ʼ
			for(int j = 1;j <= n;j++) {
				x++,y++;
				if(x>n) x -= n;//��ΧΪ1-n
				if(y>n) y -= n;
				map[x][y] = 1;num++;
				if(num==k) break;//ֻ����k��
			}
		}
		int maxr = 0,minr = INF,maxc = 0,minc = INF;
		for(int i = 1;i <= n;i++) {
			r[i] = 0;
			for(int j = 1;j <= n;j++) {
				r[i] += map[i][j];
			}
			maxr = max(maxr,r[i]);//�����ֵ
			minr = min(minr,r[i]);//��С��ֵ
		}
		for(int i = 1;i <= n;i++) {
			c[i] = 0;
			for(int j = 1;j <= n;j++) {
				c[i] += map[j][i];
			}
			maxc = max(maxc,c[i]);//�����ֵ
			minc = min(minc,c[i]);//��С��ֵ
		}
		//������
		cout<<two(maxr-minr)+two(maxc-minc)<<endl;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				cout<<map[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
