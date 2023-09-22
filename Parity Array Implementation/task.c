#include "utils.h"


void init(ParityArray *pa)
{
    pa->size;
    scanf("%d", &pa->size);
    pa->even_idx = 0;
    pa->odd_idx = pa->size-1;
    pa->intArr = (int*)malloc(pa->size * sizeof(int));
    
}

void insert(ParityArray *pa, int element)
{
    if (element % 2 == 0)
    {
        pa->intArr[pa->even_idx] = element;
        pa->even_idx++;
    }
    else
    {
        pa->intArr[pa->odd_idx] = element;
        pa->odd_idx--;
    }
    
}

void print(ParityArray *pa)
{
    for (int i = 0; i < pa->even_idx; i++)
    {
        printf("%d ", pa->intArr[i]);
    }
    
    for (int i = pa->size-1; i > pa->odd_idx; i--)
    {
        printf("%d ", pa->intArr[i]);
    }
    
}

void destruct(ParityArray *pa)
{
    free(pa->intArr);
}

void dump(ParityArray *pa)
{
    FILE* file = fopen("dump.txt","w");
    
    for (int i = 0; i < pa->even_idx; i++)
    {
        fprintf(file,"%d\n",pa->intArr[i]);
    }
    
    for (int i = pa->size-1; i > pa->odd_idx; i--)
    {
      fprintf(file,"%d\n",pa->intArr[i]);
    }
    fclose(file);
}