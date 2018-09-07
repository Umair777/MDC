#include"header.h"
#include"declarations.h"
int compress5(int fd,char *ma)
{
        unsigned char ch,c,byt,b;
        int cfd,efd,i;
	printf("%s:Begins",__func__);
        printf("Enter the name of compressed file");
        cfd=openfile("O_WRONLY");
        printf("Enter the encryption file");
        efd=openfile("O_WRONLY");
	while(1)
	{
	c^=c;
	byt^=byt;
	read(fd,&ch,1);
	b=ch;
	if(ch == 10)
	{
		byt|=0xF8;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 3;
	byt|=c;
	printf("byt is:%d\n",byt);
	
	c^=c;
	read(fd,&ch,1);
	b=ch;
	if(ch == 10)
	{
		byt|=0x07;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 3;
	c >>= 5;
	byt|=c;
	printf("byt is:%d\n",byt);
	write(cfd,&byt,1);
	
	byt^=byt;
	if(b == 10)
	{
		byt|=0xC0;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	c=(char)i;
	c <<= 6;
	byt|=c;
	printf("byt is:%d\n",byt);
	
	
	c^=c;
	read(fd,&ch,1);
	b=ch;
	if(ch == 10)
	{
		byt|=0x3E;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 3;
	c >>= 2;
	byt|=c;
	printf("byt is:%d\n",byt);
	
	
	c^=c;
	read(fd,&ch,1);
	b=ch;
	if(ch == 10)
	{
		byt|=0x01;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 3;
	c >>= 7;
	byt|=c;
	printf("byt is:%d\n",byt);	
	write(cfd,&byt,1);	
	
	c^=c;
	byt^=byt;
	if(b == 10)
	{
		byt|=0xF0;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	c=(char)i;
	c <<= 4;
	byt|=c;
	printf("byt is:%d\n",byt);
	
	
	c^=c;	
	read(fd,&ch,1);
	b=ch;
	if(ch == 10)
	{
		byt|=0x0F;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 3;
	c >>= 4;
	byt|=c;
	printf("byt is:%d\n",byt);
	write(cfd,&byt,1);

	byt^=byt;
	if(b == 10)
	{
		byt|=0x80;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	c=(char)i;
	c <<= 7;
	byt|=c;
	printf("byt is:%d\n",byt);
	
	
	c^=c;
	read(fd,&ch,1);
	b=ch;
	if(ch == 10)
	{
		byt|=0x7C;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 3;
	c >>= 1;
	byt|=c;
	printf("byt is:%d\n",byt);	
	
	c^=c;
	read(fd,&ch,1);
	b=ch;
	if(ch == 10)
	{
		byt|=0x03;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 3;
	c >>= 6;
	byt|=c;
	printf("byt is:%d\n",byt);	
	write(cfd,&byt,1);
	
	c^=c;
	byt^=byt;
	if(b == 10)
	{
		byt|=0xE0;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	c=(char)i;
	c <<= 5;
	byt|=c;
	printf("byt is:%d\n",byt);
		
	c^=c;
	read(fd,&ch,1);
//	b=ch;
	if(ch == 10)
	{
		byt|=0x1F;
		write(cfd,&byt,1);
		break;
	}
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 3;
	c >>= 3;
	byt|=c;
	printf("byt is:%d\n",byt);	
	write(cfd,&byt,1);	
	}
	write(efd,ma,strlen(ma));
	printf("%s:End\n",__func__);
}
