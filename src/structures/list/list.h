/**
 * @file list.h
 * @author peng chuan (https://github.com/PengChuan98)
 * @brief stuctures of list
 * @version 0.1
 * @date 2022-05-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _LIST_H_
#define _LIST_H_

#include "core.h"

// set node struct
struct _Node;
typedef struct _Node *PtrNode;
typedef PtrNode List;

// ! 最简单的list，单向，头插法

typedef struct _Node
{
    ElementType data;
    PtrNode next;
} Node;

bool InitList(List *list);

#endif