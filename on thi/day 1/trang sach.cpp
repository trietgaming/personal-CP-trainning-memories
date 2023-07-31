#include <iostream>
using namespace std;

int main(){
	
	long int n;cout<<"nhap so trang sach: "; cin>>n;
	
	//in ra so luong cac trang sach vua chia het cho 3 vua chia het cho 5
	int sl=0;
	for (int i=1;i<=n;i++){
		if (i%3==0 && i%5==0) sl++;
	}
	cout<<"so luong cac trang sach vua chia het cho 3 vua chia het cho 5 la : "<<sl;
	//in ra tong tat ca cac chu so cua trang sach thu n
	int sum=0;
	int t=n;
	while (t>0){
		sum+=t%10;
		t=t/10;
	}
	cout<<"\ntong cac chu so cua trang sach thu "<<n<<" bang : "<<sum;
	//in ra so luong chu so 1 da duoc dung de ghi
	int one=0;
	long int hh=0;
	for (long int i=1;i<=n;i++){
		int temp=i;
		while (temp>0){
			if (temp%10==1||temp==1)one++;
			temp/=10;
		}
	}
	cout<<"\nso luong chu so 1 da duoc dung de ghi : "<<one;
	//in danh sach cac so hoan thien
	cout<<"\ndanh sach cac so hoan thien co trong cac trang sach la: ";
	for (long int i=6;i<=n;i++){
		for (long int j=1;j<i;j++) if (i%j==0) hh+=j;
		if (hh==i) cout<<i<<" ";
		hh=0;
	}
	if (n<6)cout<<"0";
	
	return 0;
}
