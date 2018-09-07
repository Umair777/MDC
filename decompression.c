#include"header.h"
#include"declarations.h"
int decompression()
{
	char *ekey;
	int cfd,efd,ndc,cl;
	ekey=(char *)malloc(sizeof(char)*20);
	if(!ekey)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	printf("%s:Begins",__func__);
	printf("Enter the name of compressed file\n");
	cfd=openfile("O_RDONLY");
	printf("Enter the name of encryption file\n");
	efd=openfile("O_RDONLY");
	ekey=createMasterarray(efd);
	ndc=strlen(ekey);
	printf("ndc is:%d\n",ndc);
	cl=codelength(ndc);
	printf("codelength is:%d\n",cl);
	lseek(cfd,0,SEEK_SET);
	printf("%s:End",__func__);
	switch(cl)
	{
		case 2:
		{
			decompress2(cfd,ekey);
			break;
		}

		case 3:
		{
			decompress3(cfd,ekey);
			break;
		}
		case 4:
		{
			decompress4(cfd,ekey);
			break;
		}
		case 5:
		{
			decompress5(cfd,ekey);
			break;
		}
		case 6:
		{
			decompress6(cfd,ekey);
			break;
		}
		case 7:
		{
			decompress7(cfd,ekey);
			break;
		}
	}
	close(cfd);
	close(efd);
}
