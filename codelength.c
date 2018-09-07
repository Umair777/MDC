#include"header.h"
#include"declarations.h"
int codelength(int ndc)
{
if(ndc<4)
	return 2;

else if(ndc<8)
	return 3;

else if(ndc<16)
	return 4;

else if(ndc<32)
	return 5;

else if(ndc<64)
	return 6;

else if(ndc<128)
	return 7;
}
