#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
struct node{
	int tim,id;//timΪ������ʱ�䣬idΪ��ı��
	friend bool operator < (node a,node b) {
	    //�Ȱ�ʱ���С��������Ȼ���ձ������
		if(a.tim!=b.tim) return a.tim < b.tim;
		return a.id < b.id;
	}
}a[MAXN];//�洢ÿ����������Ϣ
int level[MAXN],last[MAXN],pri[MAXN];//pri��¼��ǰ���Ƿ������Ȼ�����
//level�洢ÿ��������ȼ���last��¼ÿ������һ����ŵ�ʱ��
int main() {
	int n,m,t;
	cin>>n>>m>>t;
	for(int i = 1;i <= m;i++) cin>>a[i].tim>>a[i].id;
	sort(a+1,a+m+1);//������
	for(int i = 1;i <= m;) {
		int tmp = i;
		//Ѱ��ͬһ�ҵ�ͬһʱ��Ķ�������
		while(a[tmp].id==a[i].id&&a[tmp].tim==a[i].tim&&tmp<=m) tmp++;
		int tim = a[i].tim, id = a[i].id;//��ȡ������ʱ��͵�ı��
		int cnt = tmp-i;//��ȡͬһʱ�̶���������
		i = tmp;//tmp��Ϊ��ǰ��������������һ����Ҫ����Ķ���
		level[id] -= tim-last[id]-1;//�޸Ķ������ȼ�
		//����ֻ���м䲿��û�ж��������߶��ж��������������-1
		if(level[id]<0) level[id] = 0;//��͵����ȼ�Ϊ0
		if(level[id]<=3) pri[id] = 0;//С��3����Ϊ���Ȼ���
		level[id] += cnt*2;//�����ڼ���ӵ����ȼ�
		if(level[id]>5) pri[id] = 1;//����5������뵽���Ȼ�����
		last[id] = tim;//���µ�id����һ������ʱ��
	}
	for(int i = 1;i <= n;i++) {//�������еĵ꣬�����ж��ٵĵ������Ȼ�������
		if(last[i]<t) {//����tʱ��
			level[i] -= t-last[i];// last[i]-t ��Χ�����ȼ�����Ҫ��С
			if(level[i]<=3) pri[i] = 0;//С��3���������Ȼ�������
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) ans += pri[i];//ͳ�ƽ��
	cout<<ans<<endl;
	return 0;
}
