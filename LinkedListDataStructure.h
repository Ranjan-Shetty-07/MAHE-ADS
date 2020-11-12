#ifndef LINKEDLISTDATASTRUCTURE_H_INCLUDED
#define LINKEDLISTDATASTRUCTURE_H_INCLUDED
#include <stdint.h>

typedef struct _node_ Node;
typedef struct _sList_ sList;

struct _node_ {
    int32_t     data;
    Node        *next;
};

struct _sList_{
    Node *head;
    Node *tail;
    uint32_t length;
};

sList newList();
sList addHead(sList *eList , int32_t data);
sList addtail(sList *eList , int32_t data);
sList deltail(sList *eList );
sList delHead(sList *eList );
uint8_t findKey(sList *eList , int32_t key);
int32_t length(sList *eList);

int32_t maxi(sList *eList);
int32_t mini(sList *eList);
sList addAt(sList *eList ,int8_t index , int32_t data);
sList delAt(sList *eList ,int32_t data);
sList reverseList(sList *eList);
int8_t isSame(sList *list1 , sList *list2);
sList unionList(sList *list1 , sList *list2);
sList intersection(sList *list1 , sList *list2);
sList uniqueList(sList *list1 );

#endif // LINKEDLISTDATASTRUCTURE_H_INCLUDED
