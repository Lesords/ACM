#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��������ÿ�εĻ�׼��ȡ�м�ֵ
//��ѡ�����Ϊ��׼�����ᱻ���򣨽ӽ����򣩵����鿨��O(n^2)
//ѡ���м�Ϊ��׼�����ڲ����Ĺ����У���׼����λ��Ҳ���ܱ��ƶ�

const int MAXN = 1e5 + 5;
int a[MAXN];
void quicksort(int l,int r) {           //[l,r]����������
	int left = l,right = r;
	int mid = a[(l+r)/2];               //ȡ�м�ֵΪ��׼��
	//��ȵ�ʱ����Ҫ��������Ϊ�������ĵݹ�r����l����
	while(l<=r) {
        //l��r��λ�ò�������
        //��Ϊ�߽�λ���� (l+r)/2�����λ��l��r����������
        while(a[l]<mid) l++;            //Ѱ���󲿷ִ��ڵ���mid��λ��
        while(a[r]>mid) r--;            //Ѱ���в���С�ڵ���mid��λ��
        //l���Ե���r�������������ڱ߽�λ��ʱ��
		if(l<=r) swap(a[l],a[r]),l++,r--;//����ֵ�����ƶ�l��r��λ�ã�����
	}
    if(left<r) quicksort(left,r);       //����������
	if(l<right) quicksort(l, right);    //����������
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	quicksort(1,n);
	for(int i = 1;i <= n;i++) {
		if(i!=1) cout<<' ';
		cout<<a[i];
	}
	return 0;
}
