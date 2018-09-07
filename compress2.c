#include"header.h"
#include"declarations.h"
int compress2(int fd,char *ma)
{
	unsigned char c,byt,ch,b;
        int cfd,efd,i;
        printf("%s:Begins\n",__func__);
        printf("Enter the name of Compressed file\n");
        cfd=openfile("O_WRONLY");
        printf("Enter the name of Encryption file\n");
        efd=openfile("O_WRONLY");
        while(1)
        {
        byt^=byt;
        c^=c;
        read(fd,&ch,1);
	if(ch == 10)
	{
		byt|=0xC0;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	sprintf(&c,"%c",i);
	printf("c is:%d\n",c);
	c <<= 6;
	printf("c is:%d\n",c);
	byt|=c;

	c^=c;
        read(fd,&ch,1);
	if(ch == 10)
	{
		byt|=0x30;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 6;
	c >>= 2;
	printf("c is:%d\n",c);
	byt|=c;
//	printf("byt is:%d\n",byt);
	
	c^=c;
        read(fd,&ch,1);
	if(ch == 10)
	{
		byt|=0x0C;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 6;
	c >>= 4;
	printf("c is:%d\n",c);
	byt|=c;

	c^=c;
        read(fd,&ch,1);
	if(ch == 10)
	{
		byt|=0x03;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 6;
	c >>= 6;
	printf("c is:%d\n",ch);
	byt|=c;
	write(cfd,&byt,1);
	}
	write(efd,ma,strlen(ma));

printf("%s:End",__func__);
}
