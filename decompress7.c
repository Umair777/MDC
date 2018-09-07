#include"header.h"
#include"declarations.h"
int decompress7(int cfd,char *ekey)
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
                c=ch;
                b=ch;
                c >>= 1;
                if(c == 0x7F)
                {
                        break;
                }
                i=(int)c;
                printf("Index is:%d\n",i);
                write(dfd,(ekey+i),1);
		
		b <<= 7;
		b >>= 1;
	
		c^=c;
		read(cfd,&ch,1);
		c=ch;
		c >>= 2;
		c|=b;
                if(c == 0x7F)
                {
                        break;
                }
		i=(int)c;	
                printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);
		
		b^=b;
		c^=c;
		b=ch;
		b <<= 6;
		b >>= 1;
		
		read(cfd,&ch,1);	
		c=ch;
		c >>= 3;
		c|=b;
                if(c == 0x7F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);
		
		b^=b;
		c^=c;
		b=ch;
		b <<= 5;
		b >>= 1;
		
		read(cfd,&ch,1);	
		c=ch;
		c >>= 4;
		c|=b;
                if(c == 0x7F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);

		b^=b;
		b=ch;
		b <<= 4;
		b >>= 1;
		
		c^=c;
		read(cfd,&ch,1);
		c=ch;
		c >>= 5;
		c|=b;
                if(c == 0x7F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);

		b^=b;
		c^=c;
		b=ch;
		b <<= 3;
		b >>= 1;
			
		read(cfd,&ch,1);	
		c=ch;
		c >>= 6;
		c|=b;
                if(c == 0x7F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);
	
	
		b^=b;
		c^=c;
		b=ch;
		b <<= 2;
		b >>= 1;
		
		read(cfd,&ch,1);	
		c=ch;
		c >>= 7;
		c|=b;
                if(c == 0x7F)
                {
                        break;
                }
		i=(int)c;
                printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);
		
		b^=b;
		c^=c;
		b=ch;
		b <<= 1;
		b >>= 1;
                if(c == 0x7F)
                {
                        break;
                }
		i=(int)b;
                printf("Index is:%d\n",i);
		write(dfd,(ekey+i),1);
	}	
	printf("%s:Ends\n",__func__);
}
