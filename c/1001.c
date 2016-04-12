
#include <stdio.h>

int count(int n){
	int step=0;
	while(n!=1){
		if (n%2==1)
		{
			n=(3*n+1)/2;
		}
		else{
			n=n/2;
		}
		step++;
	}
	return step;
}

int main(){
	int n=scanf("%d",&n);
	int step=count(n);
	printf("%d", step);
}

