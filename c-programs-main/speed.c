// find speed of a moving object if distance and time given

#include <stdio.h>

int main(){
	double speed , distance , time;
	printf("distance(km) = ");
	scanf("%lf",&distance);
	printf("time(h) = ");
	scanf("%lf",&time);
	speed = distance/time;
	printf("speed = %.2lfkm/h.\n",speed);

	return(0);
}