#include "lab8.h"


int read(char *file)  //used to open or create a file for orders 
{
    FILE *fp;
    char name[10];
    int size;

    fp = fopen(file, "r");
    if (fp == NULL)
    {
	fp = fopen(file, "w");
	fprintf(fp, "Name \n Size \n");
	fclose(fp);
	return;
    }
    fseek (fp, 10, SEEK_SET);
    while (fscanf(fp, "%s %d", name, &size)==2)
    {
	AddOrder (name, size);
    
    }
    fclose(fp);
    return;

}


int save(char *file)  // used for final save before closing
{
    NODE *p = Head;
    FILE *fp;
    fp = fopen(file, "w");
    fseek (fp,10, SEEK_SET);

    if( fp == NULL)
	printf ("no file found");
    while(p!=NULL)
    {
	fprintf(fp, "%s\t %d\n", p-> Name, p->drinks);
	p = p->next;
    }
    fclose (fp);
    return(1);
}


