#include"header.h"
#include"declarations.h"
int decompress3(int cfd,char *ekey)
{
	unsigned char c,b,ch;
	unsigned int i,dfd;
	printf("%s:Begin\n",__func__);
	printf("Enter the decompression file\n");
	dfd = openfile("O_WRONLY");
	while(1)
	{
	read(cfd,&ch,1);
	c=ch;
	c >>= 5;
	if(c == 0x07)
	{
		break;
	}
	i=(int)c;
	printf("Index is:%d\n",i);
	write(dfd,(ekey+i),1);

	c=ch;
	c <<= 3;
	c >>= 5;
	if(c == 0x07)
	{
		break;
	}
	i=(int)c;
	printf("Index is:%d\n",i);
	write(dfd,(ekey+i),1);

	c=ch;
	c <<= 6;
	c >>= 5;
	read(cfd,&ch,1);
	b=ch;
	b >>= 7;
	c|=b;
	if(c == 0x07)
	{
		break;
	}
	i=(int)c;
	printf("Index is:%d\n",i);
	write(dfd,(ekey+i),1);

	c=ch;
	c <<= 1;
	c >>= 5;	
	if(c == 0x07)
	{
		break;
	}
	i=(int)c;
	printf("Index is:%d\n",i);
	write(dfd,(ekey+i),1);
	
	c=ch;
	c <<= 4;
	c >>= 5;	
	if(c == 0x07)
	{
		break;
	}
	i=(int)c;
	printf("Index is:%d\n",i);
	write(dfd,(ekey+i),1);
	
	c=ch;
	c <<= 7;
	c >>= 5;
	read(cfd,&ch,1);
	b=ch;
	b >>= 6;
	c|=b;
	if(c == 0x07)
	{
		break;
	}
	i=(int)c;
	printf("Index is:%d\n",i);
	write(dfd,(ekey+i),1);
	
	c=ch;
	c <<= 2;
	c >>= 5;
	if(c == 0x07)
	{
		break;
	}
	i=(int)c;
	printf("Index is:%d\n",i);
	write(dfd,(ekey+i),1);
	
	c=ch;
	c <<= 5;
	c >>= 5;
	if(c == 0x07)
	{
		break;
	}
	i=(int)c;
	printf("Index is:%d\n",i);
	write(dfd,(ekey+i),1);
	}
	printf("%s:Ends\n",__func__);
}
