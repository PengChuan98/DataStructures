#include "sequence.h"
#include <stdlib.h>

void ShowSequence(SequenceList *list, const char *msg)
{
    printf("-> %s\n", msg);
    if (list->data == NULL)
    {
        printf("ShowSequence is empty.\n");
        printf("\n---------------------------------------------------------------------------------------\n");
        return;
    }
    printf("length: %d\n", list->length);
    printf("size: %d\n", list->size);
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n---------------------------------------------------------------------------------------\n");
}

void main()
{
    system("cls");
    SequenceList list;

    // init sequence list
    InitSequence(&list, 12);

    // create sequence value
    ElementType value[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        value[i] = i;
    }

    if (CreateSequence(&list, value, 10) == false)
        printf("CreateSequence error\n");
    else
        ShowSequence(&list,"CreateSequence");

    // insert sequence value
    int index = 0;
    InsertSequence(&list, 1024, index);
    printf("insert index is : %d\n", index);
    ShowSequence(&list,"InsertSequence");

    // append sequence value
    AppendSequence(&list, 2048);
    printf("append index is : %d\n", list.length - 1);
    ShowSequence(&list,"AppendSequence");

    // remove sequence value
    ElementType value_remove = -1;
    index = 0;
    RemoveSequenceByIndex(&list, &value_remove, index);
    printf("remove index is : %d\n", index);
    printf("remove value is : %d\n", value_remove);
    ShowSequence(&list,"RemoveSequenceByIndex");

    // merge sequence value
    SequenceList list_merge;
    InitSequence(&list_merge, 21);
    ElementType value_merge[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        value_merge[i] = i + 100;
    }
    CreateSequence(&list_merge, value_merge, 10);
    MergeSequence(&list_merge, &list);
    ShowSequence(&list_merge,"MergeSequence");

    // expand sequence and copy sequence
    SequenceList list_expand;
    SequenceList list_cp;
    CopySequence(&list_cp, &list);
    ShowSequence(&list_cp,"CopySequence");
    ExpandSequence(&list_expand, &list_cp, 20);
    ShowSequence(&list_expand,"ExpandSequence");
    

    // destroy sequence list
    DestroySequence(&list);
    ShowSequence(&list,"DestroySequence");
    
    printf("NED\n");
    printf("---------------------------------------------------------------------------------------\n");
}