#include"header.h"
#include"declarations.h"
int decompress4(int cfd,char *ekey)
{
	unsigned char c,ch;
	int dfd,i;
	unsigned int inte;
	dfd=openfile("O_WRONLY");
	printf("%s:Begin\n",__func__);
	i=0;
	while(1)
	{
		read(cfd,&ch,1);
		printf("chindc=%d\n",ch);
		c=ch;
		c >>=4;
		if(c==0x0F)
			break;
		inte =(int)c;
		printf("inte is:%d\n",inte);
		write(dfd,(ekey+inte),1);
		
		c=ch;
		c <<=4;
		c >>=4;
		if(c==0x0F)
		break;
		inte =(int)c;
		printf("inte is:%d\n",inte);
		write(dfd,(ekey+inte),1);	
	
	}
	
	printf("%s:Ends\n",__func__);
	close(dfd);
}
