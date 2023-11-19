#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void createfile(char *filename)
{
    FILE *file=fopen(filename,"w");
    if(file==NULL)
    {
        printf("ERROR OCCURRED WHILE CREATING A FILE  %s \n",filename);
    }
    else{
        printf("file creating %s successfully\n",filename);
        fclose(file);
    }
}
void deletefile(char *filename)
{
    if(remove(filename)==0)
    {
        printf("file %s deleting succefully\n",filename);
    }
    else{
       printf("ERROR OCURRED DELETING A FILE %s\n",filename);
    }
}
void copyfile(char *sourcefile,char *destinationfile)
{
   FILE *source=fopen(sourcefile,"rb");
   FILE *destination=fopen(destinationfile,"wb");
   if(source==NULL||destination==NULL)
   {
    printf("ERROR copying file\n");
    return;
   }
   char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    printf("File %s copied to %s successfully\n", sourcefile, destinationfile);

    fclose(source);
    fclose(destination);
}
void movefile(char *sourcefile,char *destinationfile)
{
    if(rename(sourcefile,destinationfile)==0)
    {
        printf("file %s is moved to %s successfully\n",sourcefile,destinationfile);
    }
    else{
        printf("Error moving file %s to %s \n",sourcefile,destinationfile);
    }
}
int main()
{
    char filename[50];
    char destinationfile[50];

    printf("Enter the filename\n");
    scanf("%s",&filename);
    printf("Choose any operation given below\n");
    printf("1.CREATE A FILE\n");
    printf("2.DELETE A FILE\n");   
    printf("3.COPY A FILE\n");   
    printf("4.MOVE A FILE\n");   

    int choice;
    printf("Enter you choice\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        createfile(filename);
        break;
        case 2:
        deletefile(filename);
        break;
        case 3:
        printf("Enter your destination file\n");
        scanf("%s",destinationfile);
        copyfile(filename,destinationfile);
        break;
        case 4:
        printf("Enter your destination file\n");
        scanf("%s",destinationfile);
        movefile(filename,destinationfile);
        break;
        default:
          printf("INVALID CHOICE");
          break;
    }
    return 0;
    
}