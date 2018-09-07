#include"header.h"
#include"declarations.h"
char * createMasterarray(int fd)
{
	int i,j,flag;
	char *ma;
	printf("%s:Begins\n",__func__);
	i=0;
	flag=0;
	ma=(char *)malloc(sizeof(char)*128);
	if(!ma)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		if(read(fd,(ma+i),1)==0)
		{
			break;
		}
		
		for(j=0;j<i;j++)
		{
			if(*(ma+i)==*(ma+j))
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("%c",*(ma+i));
			i++;
		}
		flag=0;
	}
	*(ma+i)='\0';
	printf("%s:Ends\n",__func__);
	return ma;
}

