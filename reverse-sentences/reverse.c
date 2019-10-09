#include<stdio.h>
#include<string.h>

int main() {

	printf("\n");
	printf(">>>>>>>\n");
	printf("REVERSE\n");				// opening
	printf("<<<<<<<\n\n");
	printf("Enter the sentence to be reversed :\n");

	char str[100005];
	scanf("%[^\n]s",str);
	// To scan the whole sentence

	int i, l = strlen(str);
	printf("\n");

	for (i=l-1;i>=0;i--) {

		if (str[i]==' ') {
			printf("%s ",&str[i+1]);	// Print the last word before the next NULL
			str[i] = '\0';				// Settint the last space to a NULL
		}

	}

	printf("%s\n",str);					// Printing the first word
	printf("\n End of Program :)\n\n");	// Closing

	return 0;
}