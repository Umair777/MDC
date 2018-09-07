#include"header.h"
#include"declarations.h"
int compress6(int fd,char *ma)
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
        if(b== 10)
        {
                byt|=0xFC;
                write(cfd,&byt,1);
                break;
        }
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 2;
	byt|=c;
	
	c^=c;
        read(fd,&ch,1);
        b=ch;
        if(b == 10)
        {
                byt|=0x03;
                write(cfd,&byt,1);
		break;
        }
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 2;
	c >>= 6;
	byt|=c;
	printf("byt is:%d\n",byt);
	write(cfd,&byt,1);
	
	byt^=byt;
	c^=c;
        if(b == 10)
        {
                byt|=0xF0;
                write(cfd,&byt,1);
                break;
        }
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 4;
	byt|=c;
	
	c^=c;
        read(fd,&ch,1);
        b=ch;
        if(b== 10)
        {
                byt|=0x0F;
                write(cfd,&byt,1);
                break;
        }
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 2;
	c >>= 4;
	byt|=c;
	printf("byt is:%d\n",byt);
	write(cfd,&byt,1);
	
	byt^=byt;
	c^=c;
        if(b== 10)
        {
                byt|=0xC0;
                write(cfd,&byt,1);
                break;
        }
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 6;
	byt|=c;
	
	c^=c;
        read(fd,&ch,1);
        b=ch;
        if(b== 10)
        {
                byt|=0x3F;
                write(cfd,&byt,1);
                break;
        }
	i=findindex(ch,ma);
	printf("Index of %c is %d\n",ch,i);
	c=(char)i;
	c <<= 2;
	c >>= 2;
	byt|=c;
	printf("byt is:%d\n",byt);
	write(cfd,&byt,1);	
	}
	write(efd,ma,strlen(ma));
	printf("%s:End\n",__func__);
}
