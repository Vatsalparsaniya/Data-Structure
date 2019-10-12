#include <stdio.h>
#include <math.h>

int main()
{
	int count = 0, m = 1;
	float eps = 1e-5;
	float x, term, sum = 0;
	
	printf("Enter value of x: ");
	scanf("%f", &x);
	float num = x, den = 1;
	
	do
	{
		term = num/den;
		sum += term;
		num *= -x*x;
		den *= (m+1) * (m+2);
		m += 2;
		count++;
	}while(fabs(term) >= eps);

	printf("\nSin (%0.3f) = %0.3f \n", x,sum);
	printf("Converged in %d terms.", count);
}

