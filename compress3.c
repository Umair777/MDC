#include"header.h"
#include"declarations.h"
int compress3(int fd,char *ma)
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
	b=ch;
	if(ch== 10)
	{
		byt|=0xE0;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is:%d\n",ch,i);
	c=(char)i;
	c <<= 5;
	byt=byt|c;
	printf("byt:%d\n",byt);
	c^=c;
	read(fd,&ch,1);
	b=ch;
	if(ch== 10)
	{
		byt|=0x1C;
		write(cfd,&byt,1);	
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is:%d\n",ch,i);
	c=(char)i;
	c <<= 5;
	c >>=3;
	byt=byt|c;
	printf("byt:%d\n",byt);
	c^=c;
	read(fd,&ch,1);
	b=ch;
	if(ch== 10)
	{
		byt|=0x03;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is:%d\n",ch,i);
	c=(char)i;
	c <<= 5;
	c >>= 6;
	byt=byt|c;
	printf("byt:%d\n",byt);
	write(cfd,&byt,1);
	byt^=byt;
	c^=c;
	if(b == 10)
	{
		byt|=0x80;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(b,ma);
	c=(char)i;
	c <<= 7;
	byt=byt|c;
	printf("byt:%d\n",byt);
	c^=c;
	read(fd,&ch,1);
	if(ch== 10)
	{
		byt|=0x70;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is:%d\n",ch,i);
	c=(char)i;
	c <<= 5;
	c >>= 1;
	byt=byt|c;
	printf("byt:%d\n",byt);
	c^=c;
	read(fd,&ch,1);
	b=ch;
	if(ch== 10)
	{
		byt|=0x0E;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is:%d\n",ch,i);
	c=(char)i;
	c <<= 5;
	c >>= 4;
	byt=byt|c;
	printf("byt:%d\n",byt);
	c^=c;
	read(fd,&ch,1);
	b=ch;
	if(ch== 10)
	{
		byt|=0x01;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is:%d\n",ch,i);
	c=(char)i;
	c <<= 5;
	c >>= 7;
	byt=byt|c;
	printf("byt:%d\n",byt);
	write(cfd,&byt,1);
	byt^=byt;
	c^=c;
	if(b == 10)
	{
		byt|=0xC0;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(b,ma);
	c=(char)i;
	c <<= 6;
	byt=byt|c;
	printf("byt:%d\n",byt);
	c^=c;
	read(fd,&ch,1);
	b=ch;
	if(ch== 10)
	{
		byt|=0x38;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is:%d\n",ch,i);
	c=(char)i;
	c <<= 5;
	c >>= 2;
	byt=byt|c;
	printf("byt:%d\n",byt);
	c^=c;
	read(fd,&ch,1);
	if(ch== 10)
	{
		byt|=0x07;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is:%d\n",ch,i);
	c=(char)i;
	byt=byt|c;		
	printf("byt:%d\n",byt);
	write(cfd,&byt,1);
	}
	write(efd,ma,strlen(ma));
	printf("%s:End\n",__func__);
}
