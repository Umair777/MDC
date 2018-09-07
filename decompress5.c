#include"header.h"
#include"declarations.h"
int decompress5(int cfd,char *ekey)
{
	unsigned char c,b,ch;
        unsigned int i,dfd;
        printf("%s:Begin\n",__func__);
        printf("Enter the decompression file\n");
        dfd = openfile("O_WRONLY");
	while(1)
	{	c^=c;
		b^=b;
		read(cfd,&ch,1);
		c=ch;
		b=ch;
		c >>= 3;
		printf("c:%d\n",c);
		if(c == 0x1F)
		{
			break;
		}
		i=(int)c;
		printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);
		
		c^=c;
		c=b;
		c <<= 5;
		c >>= 3;

		b^=b;
		read(cfd,&ch,1);
                b=ch;
                b >>= 6;
		c|=b;
		printf("c:%d\n",c);
		if(c == 0x1F)
                {
                        break;
                }
                i=(int)c;
                printf("Index is:%d\n",i);
                write(dfd,(ekey+i),1);

		c^=c;
		c=ch;
		printf("c:%d\n",c);
		c <<= 2;
		c >>= 3;
		printf("c:%d\n",c);
		if(c == 0x1F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
                write(dfd,(ekey+i),1);
		
		c^=c;
		c=ch;
		c <<= 7;
		c >>= 3;
		
		read(cfd,&ch,1);
		b=ch;
		b >>= 4;
		c|=b;
		printf("c:%d\n",c);
		if(c == 0x1F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
                write(dfd,(ekey+i),1);
	
		c^=c;
		c=ch;
		c <<= 4;
		c >>= 3;
		
		b^=b;
		read(cfd,&ch,1);
		b=ch;
		b >>= 7;
		c|=b;
		printf("c:%d\n",c);
		if(c == 0x1F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
                write(dfd,(ekey+i),1);
	
		c^=c;
		c=ch;
		c <<= 1;
		c >>= 3;			
		printf("c:%d\n",c);
		if(c == 0x1F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
                write(dfd,(ekey+i),1);
		
		c^=c;
		c=ch;
		c <<= 6;
		c >>= 3;
		
		b^=b;
		read(cfd,&ch,1);
		b=ch;
		b >>= 5;
		c|=b;
		printf("c:%d\n",c);
		if(c == 0x1F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
                write(dfd,(ekey+i),1);
		
		c^=c;
		c=ch;
		c <<= 3;
		c >>= 3;
		if(c == 0x1F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
                write(dfd,(ekey+i),1);
			
	}	
	printf("%s:Ends\n",__func__);
}
