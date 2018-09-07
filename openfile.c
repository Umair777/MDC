#include"header.h"
#include"declarations.h"
int openfile(char *mode)
{
	char *file;
	int fd;
	printf("%s:Begin\n",__func__);
        file=(char *)malloc(sizeof(char)*20);
	if(!file)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	printf("Enter filename");
	scanf("%s",file);
	if(strncmp("O_RDONLY",mode,8)==0)
	{	
	
		fd=open(file,O_RDONLY);
		if(fd==-1)
		{	
			perror("open");
			exit(EXIT_FAILURE);
		}
	
	}
	else if(strncmp("O_WRONLY",mode,8)==0)
	{
		fd=open(file,O_WRONLY|O_CREAT);

		if(fd==-1)
		{	
			perror("open");
			exit(EXIT_FAILURE);
		}
	
	}
	else
		{
		printf("Invalid mode");
		exit(EXIT_FAILURE);
		}
	printf("%s:Ends\n",__func__);
	return fd;
}
