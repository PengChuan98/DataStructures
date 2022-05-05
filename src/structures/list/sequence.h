/**
 * @file sequence.h
 * @author peng chuan (https://github.com/PengChuan98)
 * @brief sequence data structures
 * @version 0.1
 * @date 2022-05-03
 *
 * @copyright Copyright (c) 2022
 *
 */

// ! start from zeor !!!

#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include "core.h"
#include <stdio.h>
#include <malloc.h>

typedef struct _sequence_t
{
    int length;
    int size;
    ElementType *data;
} SequenceList;

// init sequence list
bool InitSequence(SequenceList *list, int length);
bool IsFullSequence(SequenceList *list);
bool CreateSequence(SequenceList *list, ElementType *value, int length);
bool InsertSequence(SequenceList *list, ElementType value, int index);
bool AppendSequence(SequenceList *list, ElementType value);
bool RemoveSequenceByIndex(SequenceList *list, ElementType *value, int index);
bool RemoveSequenceByValue(SequenceList *list, ElementType value, bool (*Compare)(ElementType a, ElementType b));
bool MergeSequence(SequenceList *dst, SequenceList *src);
bool ExpandSequence(SequenceList *dst, SequenceList *src, int size);
bool CopySequence(SequenceList *dst, SequenceList *src);
bool DestroySequence(SequenceList *list);

#endif
