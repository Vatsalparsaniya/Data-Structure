#include <stdio.h>

int main(){
	int a = (int)__TIME__[7]-45;
	int b = (int)__TIME__[6]-45;
	for(int i = 1;i<b;++i){
		a = 3*a+1;
	}
	printf("%d\n",a);
	while(786){
		int guess;
		printf("Enter your guess : ");
		scanf("%d",&guess);
		if(guess==a){
printf(" _________________ \n");
printf("< WOW you find it >\n");
printf(" ----------------- \n");
printf("        \\   ^__^ \n");
printf("         \\  (oo)\\______\n");
printf("            (__)\\       )\\/\n");
printf("                ||----w |\n");
printf("                ||     ||\n");

			break;
		}
		else if(guess<a)
			printf("your guess is small.\n");
		else
			printf("your guess is large.\n");
	}
	return(0);
}