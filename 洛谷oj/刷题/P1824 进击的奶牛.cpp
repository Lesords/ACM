#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],n,c;
bool check(int mid) {
//��һ����ţ�϶����ڵ�һ�����䣬����ֻ��Ҫ�ж�ʣ��ļ���
	int pos = 1,next = 2,num = 2;
	//posΪ��ǰλ�ã�nextΪ��һ����ţ��λ��
	while(num<=c) {//��c����ţ
		//��Խ�粢�Ҿ���Ҫ����>=mid
		while(next<=n&&a[next]-a[pos]<mid) next++;
		if(next>n) return 0;//���next���ˣ�˵��������
		pos = next++;//���µ�ǰλ�ú���һλ��
		num++;//�ѷ������ţ����++
	}
	return 1;
}
int main() {
	cin>>n>>c;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);//��С��������
	//���ֵ����ֵΪ��β�ľ���
	int l = 1,r = a[n]- a[1],ans = 0;//ans��ʼ��Ϊ0
	while(l<=r) {//���ֲ��Ҵ�
		int mid = (l+r)/2;
		if(check(mid)) ans = mid,l = mid+1;
		else r = mid-1;
	}
	cout<<ans;
	return 0;
}
