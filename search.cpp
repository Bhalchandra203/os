#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>

void search(char c, char *filename, char *pattern) 
{
	int fp, i=1, cnt=0, j=0;
	char buff[80], ch, *p;
	
	if((fp = open(filename, O_RDONLY)) == -1)
	{
		printf("File %s is not found.\n\n", filename);
		return;
	}
	
	switch(c) 
	{
		case 'a':
			while(read(fp, &ch, 1) != 0) 
			{
				if(ch == '\n') 
				{
					buff[j] = '\0';
					j=0;
					if(strstr(buff, pattern) != NULL) 
					{
						printf("%d : %s\n", i, buff);
						i++;
					}
				} 
				else 
				{
					buff[j] = ch;
					j++;
				}
			}
			printf("\n");
			break;
		case 'c':
			while(read(fp, &ch, 1) != 0) 
			{
				if(ch == '\n') 
				{
					buff[j] = '\0';
					j=0;
					if(strstr(buff, pattern) != NULL) 
					{
						p = buff;
						while((p = strstr(p, pattern)) != NULL) 
						{
							cnt++;
							p++;
						}
		 			}
				} 
				else 
				{
					buff[j] = ch;
					j++;
				}
			}
			printf("Total no. of occerences = %d\n\n", cnt);
	}
}

int main() 
{
	char command[80], t1[20], t2[20], t3[20], t4[20];
	int n;
	
	system("clear");
	
	while(1) 
	{
		printf("myshell$:> ");
		fflush(stdin);
		
		fgets(command, 80, stdin);
		n = sscanf(command, "%s %s %s %s", t1, t2, t3, t4);
		
		if(n == 4) 
		{
			if(strcmp(t1, "search") == 0) 
			{
				search(t2[0], t3, t4);
			} 
			else 
			{
				printf("%s is invalid command.\n\n", t1);
			}
		} 
		else 
		{
			printf("please enter command in this pattern(search a/c filename pattern).\n\n");		
		}
	
	}

	return 0;
}
 
