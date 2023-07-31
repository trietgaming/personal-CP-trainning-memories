#include <stdio.h>

int main()
{
    int a,b,p;
    scanf("%d %d %d",&a,&b,&p);
    int uoc=0;
    for (int i=a;i<=b;i++){
    	if (p%i==0)uoc++;
		}
	if (uoc>0)
   printf("co it nhat %d so trong doan [%d,%d] la uoc cua %d",uoc,a,b,p);
   else
   printf("khong co so nao trong doan [%d,%d] la uoc cua %d",a,b,p);
    
    return 0;
}
