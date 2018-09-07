#include"header.h"
#include"declarations.h"
int decompress6(int cfd,char *ekey)
{
	unsigned char c,b,ch;
        unsigned int i,dfd;
        printf("%s:Begin\n",__func__);
        printf("Enter the decompression file\n");
        dfd = openfile("O_WRONLY");
        while(1)
        {       c^=c;
                b^=b;
                read(cfd,&ch,1);
		printf("character read :%d\n",ch);
                c=ch;
                c >>= 2;
                printf("c:%d\n",c);
                if(c == 0x3F)
                {
                        break;
                }
                i=(int)c;
                printf("Index is:%d\n",i);
                write(dfd,(ekey+i),1);
		
		c^=c;
		c=ch;
		c <<= 6;
		c >>= 2;
		
		b^=b;
		read(cfd,&ch,1);
		printf("character read :%d\n",ch);
		b=ch;
		b >>= 4;
		c|=b;
                printf("c:%d\n",c);
                if(c == 0x3F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);
		
		c^=c;
		c=ch;
		c <<= 4;
		c >>= 2;
		
		b^=b;	
		read(cfd,&ch,1);
		printf("character read :%d\n",ch);
		b=ch;
		b >>= 6;
		c|=b;
                printf("c:%d\n",c);
                if(c == 0x3F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);
		
		c^=c;
		c=ch;
		c <<= 2;
		c >>= 2;
                if(c == 0x3F)
                {
                        break;
                }
		i=(int)c;
		printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);
	}

	printf("%s:Ends\n",__func__);
}
