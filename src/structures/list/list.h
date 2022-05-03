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

// set element type
typedef int ElementType;

// set node struct
struct _Node;
typedef struct _Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef struct _Node
{
    ElementType data;
    Position next;
} Node;




#endif