#include<string.h>
#include<stdio.h>

int main(int argc, int * argv){
	char buf[256];
	strcpy(buf, argv[1]);
	printf("%s\n", buf);
	return 0;
}
