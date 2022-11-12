
#ifndef PQUEUE_H
#define PQUEUE_H

#include "../Makanan/makanan.h"
#include "../Boolean/boolean.h"
#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------
//silahkan edit typdef dan define sesuai keperluan tipe elemen
//-------------------------------------------------------------

typedef Makanan ElTypePQueue;
//typedef int ElTypePQueue;
// typedef reducedMakanan {
//     int id;
//     int prio;
// } ElTypePQueue;

typedef Kata CompareType;
// typedef int CompareType;

typedef boolean (*lambdaPQ)(ElTypePQueue,CompareType);

typedef struct{
    ElTypePQueue* queue;
    int idxHead;
    int idxTail;
    int size;
} PQueue;

#define IDX_UNDEFF -1

#define GetPrio(m) timeToMin(Expired(m))
#define GetPrio2(m) timeToMin(DelivTime(m))
//#define GetPrio(m) (m)
// #define GetPrio(m) (m).prio

#define Queue(m) (m).queue
#define IdxHead(m) (m).idxHead
#define IdxTail(m) (m).idxTail
#define SizePQueue(m) (m).size
#define Head(m) (m).queue[IdxHead(m)]
#define ElmtPQueue(m,i) (m).queue[i]

// reducedMakanan mToRM(Makanan m, time prio);

void createPQueue(PQueue* p, int nMax);

boolean isEmptyPQueue(PQueue p);//head tail idx undef
boolean isFullPQueue(PQueue p);//queue penuh

void enqueue(PQueue* p, ElTypePQueue val);//enqueue sperti prioqueue berdasar priority
void enqueue2(PQueue* p, ElTypePQueue val);
void dequeue(PQueue* p, ElTypePQueue* val);//pop head(?)

boolean removeFromQueue(PQueue* p, lambdaPQ fx, CompareType val);//search ElmtPQueue yang sesuai dengan
                                                            //fungsi lambda boolean dan value
                                                            //*lihat driver untuk lebih memahami
                                                            //return true bila ada yg dihapus

int lengthPQueue(PQueue p); //return len

void resizePQueue(PQueue* p); //resizePQueue

ElTypePQueue getElmtPQueue(PQueue p, int idx); //getElmtPQueue pass by value

ElTypePQueue* getElmtPQueueReff(PQueue* p, int idx); //getElmtPQueue pass by refference

void destroyPQueue(PQueue* p); //free()

PQueue copyQ(PQueue p);

//fungsi tambahan
// hanya berlaku bila ElType Makanan
boolean isIdInQueue(PQueue p, int id);
boolean removeIdFromQueue(PQueue* p, int id);

#endif