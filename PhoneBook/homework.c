#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct 
{
    char name[30];
    char phoneNumber[30];
}typedef entry;

struct 
{
entry *entrys;
int numOfInsert;
int actualSize;
}typedef phone_book;

phone_book p1;
entry e1;
void init(int size)
{
    p1.actualSize = size;
    p1.entrys = (entry*)malloc(p1.actualSize * sizeof(entry));
    p1.numOfInsert = 0;
}

void destroy()
{
    free(p1.entrys);
}
bool insert( char nameNew[30], char numberNew[30])
{
    int occurence = 0;
    for (int i = 0; i < p1.actualSize; i++)
    {
        if (strcmp(p1.entrys[i].name, nameNew) == 0)
        {
            occurence++;
            printf("The user's number is already in the phonebook, lets overwrite.\n");
            strcpy(p1.entrys[i].phoneNumber, numberNew);
            return true;
        }
        
        
    }
    
    
    if (p1.numOfInsert < p1.actualSize && occurence == 0)
    {
        strcpy(p1.entrys[p1.numOfInsert].name, nameNew);
        strcpy(p1.entrys[p1.numOfInsert].phoneNumber, numberNew);
        p1.numOfInsert++;
        printf("Contact successfully added.\n");
        return true;
    }
    else if (p1.numOfInsert == p1.actualSize)
    {
        printf("There is no space.\n");
        return false;
    }
    
        
}

char * get(char name[30])
{
    for (int i = 0; i < p1.numOfInsert; i++)
    {
        if (strcmp(p1.entrys[i].name, name) == 0)
        {
            printf("The number of the given user is:\n");
            return p1.entrys[i].phoneNumber;
        }
        
    }

    return NULL;
}
void print()
{
    for (int i = 0; i < p1.numOfInsert; i++)
    {
        printf("the phone number of %s is %s\n",p1.entrys[i].name, p1.entrys[i].phoneNumber);
    }
}

void dump(char fileName[30])
{
    FILE* file = fopen(fileName,"w");
    
    
    for (int i = 0 ; i < p1.numOfInsert ; i++ )
    {
        fprintf(file,"%s %s\n",p1.entrys[i].name, p1.entrys[i].phoneNumber);
    }
    fclose(file);
}


int main()
{
    init(10);
    insert("Jamil", "555");
    printf("%s\n",get("Jamil"));
    insert("Ravan", "444");
    insert("Jamil", "111");
    insert("Rick", "222");
    insert("Michael", "333");
    insert("Christian", "777");
    insert("Gustavo", "0111");
    insert("Eduardo", "0101");
    insert("Ashraf", "0102");
    insert("Cristiano", "0103");
    insert("Mahmood", "999");
    insert("Mahmood1", "999"); // at this point there is no space because init function's parameter is 10
    insert("Mahmood2", "999");



    


    print();
    dump("data.txt");
    destroy();
    return 0;
}