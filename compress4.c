#include"header.h"
#include"declarations.h" 
int compress4(int fd,char *ma)
{
	printf("%s:Begins\n",__func__);
	unsigned char c,byt;
	unsigned char ch;
	int cfd,efd,i;
	printf("Enter the name of compressed file");
	cfd=openfile("O_WRONLY");
	printf("Enter the encryption file");
	efd=openfile("O_WRONLY");
	while(1)
	{
		c^=c;
		byt^=byt;
		read(fd,&ch,1);
		if (ch == 10)
		{
			byt=byt|0xF0;
			write(cfd,&byt,1);
			break;
		}
		i=findindex(ch,ma);	
		printf("index of %c is : %d\n",ch,i);
		c=(char)i;
		c <<= 4;
		byt=byt|c;
		read(fd,&ch,1);
		if (ch == 10)
		{
			byt=byt|0x0F;
			write(cfd,&byt,1);
			break;
		}
		i=findindex(ch,ma);
		printf("index of %c is : %d\n",ch,i);
		c=(char)i;
		c <<= 4;
		c >>= 4;
		byt=byt|c;
		printf("byt=%d\n",byt);
		write(cfd,&byt,1);
	}
	write(efd,ma,strlen(ma));
	printf("%s:End\n",__func__);
	close(cfd);
	close(efd);
	return 0;
}
