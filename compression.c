#include"header.h"
#include"declarations.h"
int compression()
{
	int fd,ndc,cl;
	char *ma;
	printf("%s:Begin\n",__func__);
	fd=openfile("O_RDONLY");
	printf("File descriptor is:%d\n",fd);
	ma = createMasterarray(fd);
	ndc=strlen(ma);
	cl=codelength(ndc);
	printf("No. of distinct characters are:%d\n",ndc);
	printf("Codelength is:%d\n",cl);
	lseek(fd,0,SEEK_SET);
	switch(cl)
	{
		case 2:
			{
				compress2(fd,ma);
				break;
			}

		case 3:
			{
				compress3(fd,ma);
				break;
			}

		case 4:
			{
				compress4(fd,ma);
				break;
			}

		case 5:
			{
				compress5(fd,ma);
				break;
			}

		case 6:
			{
				compress6(fd,ma);
				break;
			}

		case 7:
			{
				compress7(fd,ma);
				break;
			}
	}
	printf("%s:Ends\n",__func__);
	close(fd);
}

