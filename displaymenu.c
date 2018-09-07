#include"header.h"
int displaymenu()
{
char choice;
printf("%s:Begin\n",__func__);
printf("__MAIN__\n");
printf("C:__compression__\n");
printf("D:__decompression__\n");
printf("E:__exit__\n");
printf("%s: End\n",__func__);
printf("enter choice\n");
scanf("%c",&choice);
return choice;
}
