#include<stdio.h>
void main()
{
for(int i=0;i<6;i++){
	if(i==5)
		goto end;
	printf("%d\n",i);

}
end:
	printf("\nEnd Occured !\n");
}
