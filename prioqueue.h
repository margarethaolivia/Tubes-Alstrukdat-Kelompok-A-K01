
#ifndef PQUEUE_H
#define PQUEUE_H

#include "makanan.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------
//silahkan edit typdef dan define sesuai keperluan tipe elemen
//-------------------------------------------------------------

//typedef Makanan ElTypePQueue;
typedef int ElTypePQueue;

//typedef Kata CompareType;
typedef int CompareType;

typedef boolean (*lambdaPQ)(ElTypePQueue,CompareType);

typedef struct{
    ElTypePQueue* queue;
    int idxHead;
    int idxTail;
    int size;
} PQueue;

#define IDX_UNDEFF -1

//#define GetPrio(m) timeToMin(Expired(m))
#define GetPrio(m) (m)

#define Queue(m) (m).queue
#define IdxHead(m) (m).idxHead
#define IdxTail(m) (m).idxTail
#define Size(m) (m).size
#define Head(m) (m).queue[IdxHead(m)]
#define Elmt(m,i) (m).queue[i]

void createPQueue(PQueue* p, int nMax);

boolean isEmpty(PQueue p);//head tail idx undef
boolean isFull(PQueue p);//queue penuh

void enqueue(PQueue* p, ElTypePQueue val);//enqueue sperti prioqueue berdasar priority
void dequeue(PQueue* p, ElTypePQueue* val);//pop head(?)

boolean removeFromQueue(PQueue* p, lambdaPQ fx, CompareType val);//search Elmt yang sesuai dengan
                                                            //fungsi lambda boolean dan value
                                                            //*lihat driver untuk lebih memahami
                                                            //return true bila ada yg dihapus

int length(PQueue p); //return len

void resize(PQueue* p); //resize

ElTypePQueue getElmt(PQueue p, int idx); //getElmt pass by value

ElTypePQueue* getElmtRef(PQueue* p, int idx); //passby referens untuk otak atik data elmt queue

void destroy(PQueue* p); //free()

void updateElmtPriority(PQueue* p, int amount);


#endif