#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	FILE *f = fopen("caplog.txt", "a");
	
	if (f == NULL)
	{
		printf("Error opening file...\n");
		exit(1);
	}


	time_t now = time(NULL);
	struct tm *local_time = localtime(&now);

	char buffer[3000];
	fgets(buffer, sizeof(buffer), stdin); 
	fprintf(f, "%s\n %s\n", asctime(local_time), buffer);

	fclose(f);
	return 0;
}
