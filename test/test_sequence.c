#include "sequence.h"
#include <stdlib.h>

void ShowSequence(SequenceList *list)
{
    if (list->data == NULL)
    {
        printf("ShowSequence is empty.\n");
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
        ShowSequence(&list);

    // insert sequence value
    int index = 0;
    InsertSequence(&list, 1024, index);
    printf("insert index is : %d\n", index);
    ShowSequence(&list);

    // append sequence value
    AppendSequence(&list, 2048);
    printf("append index is : %d\n", list.length - 1);
    ShowSequence(&list);

    // remove sequence value
    ElementType value_remove = -1;
    index = 0;
    RemoveSequenceByIndex(&list, &value_remove, index);
    printf("remove index is : %d\n", index);
    printf("remove value is : %d\n", value_remove);
    ShowSequence(&list);

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
    ShowSequence(&list_merge);

    // destroy sequence list
    DestroySequence(&list);
    ShowSequence(&list);
}