#include"header.h"
#include"declarations.h"
int findindex(char ch,char *ma)
{
	int i,ndc;
	ndc=strlen(ma);
	for(i=0;i<ndc;i++)
	{
		if(ch ==*(ma+i))
		{
			break;
		}

	} 	
	return i;
}
