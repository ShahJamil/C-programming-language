#include "utils.h"

int main(int argc, char * argv[])
{
    ParityArray pa;

    // init(&pa);

    // insert(&pa, 5);
    // insert(&pa, 4);
    // insert(&pa, 3);
    // insert(&pa, 2);

    

    init(&pa);
    for (int i = 0; i < pa.size; i++)
    {
        int elem;
        scanf("%d", &elem);
        insert(&pa, elem);
    }
    
    print(&pa);
    dump(&pa);
    destruct(&pa);
    return 0;
}