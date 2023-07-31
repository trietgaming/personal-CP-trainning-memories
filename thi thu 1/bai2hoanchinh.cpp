#include <iostream>
using namespace std;

int main(){
	float h,m,k,va,vb; 
	do{
	
	cout<<"h: ";cin>>h;
	if(h>=25)cout<<"vui long nhap so gio nho hon hoac bang 24! \n";
}while (h>=25);
	do{
	
	cout<<"m: ";cin>>m;
	if (m>59)cout<<"vui long nhap m <= 59! \n";
} while (m>59);
	cout<<"k: ";cin>>k;

	do{
	cout<<"va: ";cin>>va;
	cout<<"vb: ";cin>>vb;
	if (va>=vb ||vb>60 || vb<=0 ||va<=0 )cout<<"vui long nhap va, vb hop le! \n";
} while (va>=vb || vb>60 || vb<=0 || va<=0);
int tg = ( ( ( va*(k/60) )/(vb-va) ) *60) + k ;
int m1=m,h1=h;

for (int i=m;i<m+tg;i++){
	m1++;
	if (m1==60){h1++;m1=0;}
	if (h1==25)h1=1;
}
cout<<"thoi gian de nhan vien gap nguoi du lich bui: "<<h1<<" gio "<<m1<<" phut";
return 0;
}
