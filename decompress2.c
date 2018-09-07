#include"header.h"
#include"declarations.h"
int decompress2(int cfd,char *ekey)
{
	unsigned char c,b,ch;
        unsigned int i,dfd;
        printf("%s:Begin\n",__func__);
        printf("Enter the decompression file\n");
        dfd = openfile("O_WRONLY");
        while(1)
        {       c^=c;
     //           b^=b;
                read(cfd,&ch,1);
                c=ch;
                c >>= 6;
                if(c == 0x03)
                {
                        break;
                }
		i=(int)c;
		write(dfd,(ekey+i),1);
		
		c^=c;
		c=ch;
		c <<= 2;
		c >>= 6;
                if(c == 0x03)
                {
                        break;
                }
		i=(int)c;
		write(dfd,(ekey+i),1);

		c^=c;
		c=ch;
		c <<= 4;
		c >>= 6;
                if(c == 0x03)
                {
                        break;
                }
		i=(int)c;
		write(dfd,(ekey+i),1);
		

		c^=c;
		c=ch;
		c <<= 6;
		c >>= 6;
                if(c == 0x03)
                {
                        break;
                }
		i=(int)c;
		write(dfd,(ekey+i),1);
	}
	printf("%s:Ends\n",__func__);
}
