#include"header.h"
#include"declarations.h"
int main()
{
	char ret;
	ret=displaymenu();
	switch(ret)
{
	case 'C':
	{
		compression();
		break;
	}

	case 'D':
	{
		decompression();
		break;
	}

	case 'E':
	{
		exit(EXIT_SUCCESS);
		break;
	}

}
	
	
	return 0;
}

