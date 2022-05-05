#include "sequence.h"

bool InitSequence(SequenceList *list, int length)
{
    if (length <= 0)
    {
        printf("InitSequence error: length must be greater than 0\n");
        return false;
    }

    list->length = 0;
    list->size = length;
    list->data = (ElementType *)malloc(sizeof(ElementType) * length);
    if (list->data == NULL)
    {
        printf("InitSequence error: malloc error\n");
        return false;
    }
    return true;
}

bool IsFullSequence(SequenceList *list)
{
    if (list->length < list->size)
        return false;
    else
        return true;
}

bool CreateSequence(SequenceList *list, ElementType *value, int length)
{
    if (length <= 0)
    {
        printf("CreateSequence error: length must be greater than 0\n");
        return false;
    }
    else if (length > list->size)
    {
        printf("CreateSequence error: length must be less than or equal to list->size\n");
        return false;
    }

    // correct
    else
    {
        for (int i = 0; i < length; i++)
        {
            list->data[i] = value[i];
        }
        list->length = length;
        return true;
    }
}

/**
 * @brief 插入函数
 * 这里的插入index从0开始，>=index的值向后移动一位
 * @param list
 * @param value
 * @param index
 * @return true
 * @return false
 */
bool InsertSequence(SequenceList *list, ElementType value, int index)
{
    if (IsFullSequence(list) == true)
    {
        printf("InsertSequence error: list is full\n");
        return false;
    }

    if (index >= list->size || index > list->length)
    {
        printf("InsertSequence error: index must be less than list->size and list->length\n");
        return false;
    }
    else if (index < 0)
    {
        printf("InsertSequence error: index must be greater than 0\n");
        return false;
    }
    else
    {
        // >=index位置的值往后移动一个位置，从后往前
        for (int i = list->length; i > index; i--)
        {
            list->data[i] = list->data[i - 1];
        }
        list->data[index] = value;
        list->length++;
        return true;
    }
}

bool AppendSequence(SequenceList *list, ElementType value)
{
    if (IsFullSequence(list) == true)
    {
        printf("AppendSequence error: list is full\n");
        return false;
    }

    list->data[list->length] = value;
    list->length++;
    return true;
}

/**
 * @brief remove element by index value
 * >value 的值向前移动一位
 * @param list
 * @param value remove value
 * @param index
 * @return true
 * @return false
 */
bool RemoveSequenceByIndex(SequenceList *list, ElementType *value, int index)
{
    if (index < 0)
    {
        printf("RemoveSequenceByIndex error: index must be greater than 0\n");
        return false;
    }
    else if (index >= list->length)
    {
        printf("ReomveSequenceByIndex error: index must be less than list->length\n");
        return false;
    }
    else
    {
        // 向前移动
        *value = list->data[index];
        for (int i = index; i < list->length; i++)
        {
            list->data[i] = list->data[i + 1];
        }
        list->length--;

        return true;
    }
}

bool RemoveSequenceByValue(SequenceList *list, ElementType value, bool (*Compare)(ElementType a, ElementType b))
{
    // WARNING 这里的查找是按照值来查找的，不是按照索引来查找的
    // WARNING 但是有个非常非常重要的问题，Element的类型必须是可以比较的
    // WARNING 如果不可以比较，那么就没有办法查找到元素了
    // WARNING SO，最好的办法还是传入一个比较函数，这样就可以按照比较函数来查找了
    return false;
}

/**
 * @brief merge two sequence
 * [ dst + src ]
 * @param dst return list
 * @param src append list
 * @return true
 * @return false
 */
bool MergeSequence(SequenceList *dst, SequenceList *src)
{
    if (dst->length + src->length > dst->size)
    {
        printf("MergeSequence error: dst->length + src->length must be less than dst->size\n");
        return false;
    }
    else
    {
        for (int i = 0; i < src->length; i++)
        {
            dst->data[dst->length + i] = src->data[i];
        }
        dst->length += src->length;
        return true;
    }
}

/**
 * @brief
 * expand the size of list
 * @param dst
 * @param src
 * @param size
 * @return true
 * @return false
 */
bool ExpandSequence(SequenceList *dst, SequenceList *src, int size)
{
    if (size <= 0)
    {
        printf("ExpandSequence error: size must be greater than 0\n");
        return false;
    }

    // reset dst
    if (InitSequence(dst, src->size + size) && MergeSequence(dst, src) && DestroySequence(src))
    {
        return true;
    }
    else
    {
        printf("ExpandSequence error: init or merge failed\n");
        return false;
    }
}

bool CopySequence(SequenceList *dst, SequenceList *src)
{
    if (InitSequence(dst, src->size) && MergeSequence(dst, src))
    {
        return true;
    }
    else
    {
        printf("CopySequence error: init or merge failed\n");
        return false;
    }
}

bool DestroySequence(SequenceList *list)
{
    if (list->data == NULL)
    {
        printf("DestroySequence error: list->data is NULL\n");
        return false;
    }
    else
    {
        free(list->data);
        list->data = NULL;
        list->length = 0;
        list->size = 0;
        return true;
    }
}
