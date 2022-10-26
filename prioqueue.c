#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

void createPQueue(PQueue* p, int nMax){
    Queue(*p) = (ElTypePQueue*)malloc(sizeof(ElTypePQueue)*nMax);
    IdxHead(*p) = IDX_UNDEFF;
    IdxTail(*p) = IDX_UNDEFF; //blablabla init
    SizePQueue(*p) = nMax;

}

boolean isEmptyPQueue(PQueue p){
    return IdxHead(p)==IDX_UNDEFF; //is empty
}

boolean isFullPQueue(PQueue p){
    if(IdxTail(p)>IdxHead(p)){
        return IdxTail(p)==(SizePQueue(p)-1)&&IdxHead(p)==0; //is full
    } else {
        return (IdxHead(p)-IdxTail(p))==1;
    }
}

void enqueue(PQueue* p, ElTypePQueue val){
    if(isEmptyPQueue(*p)){
        ElmtPQueue(*p,0) = val;
        IdxTail(*p) = 0;            //is empty? enqu
        IdxHead(*p) = 0;
    }
    else if(!isFullPQueue(*p)){
        int startTraversal = IdxHead(*p);
        int endTraversal = IdxTail(*p);
        if(endTraversal<startTraversal){endTraversal+=SizePQueue(*p);}

        int i = startTraversal;
        while(i<=endTraversal&&GetPrio(ElmtPQueue(*p,i%SizePQueue(*p)))<=GetPrio(val)){
            i++;
        }
        if(GetPrio(ElmtPQueue(*p,i%SizePQueue(*p)))==GetPrio(val)){i++;}   //sortby prio

        int j;
        for(j=endTraversal+1;j>i;j--){
            ElmtPQueue(*p,j%SizePQueue(*p)) = ElmtPQueue(*p,(j-1)%SizePQueue(*p));      //ser geser
        }

        ElmtPQueue(*p,i%SizePQueue(*p)) = val;
        
        IdxTail(*p) = (endTraversal+1)%SizePQueue(*p);
    }
    else if(isFullPQueue(*p)){
        resizePQueue(p);                  //full? resizePQueue
        enqueue(p,val);
    }
}

void dequeue(PQueue* p, ElTypePQueue* val){
    if(!isEmptyPQueue(*p)){
        *val = Head(*p);
        
        IdxHead(*p) = (IdxHead(*p)+1)%SizePQueue(*p);
        if(IdxHead(*p)==(IdxTail(*p)+1)%SizePQueue(*p)){      //pop head??
            IdxHead(*p)=IDX_UNDEFF;
            IdxTail(*p)=IDX_UNDEFF;
        }
        
    }
}

boolean removeFromQueue(PQueue* p, lambdaPQ fx, CompareType val){
    if(!isEmptyPQueue(*p)){
        int startTraversal = IdxHead(*p);
        int endTraversal = IdxTail(*p);
        if(endTraversal<startTraversal){endTraversal+=SizePQueue(*p);}

        int i = startTraversal;
        while(i<endTraversal&&!fx(ElmtPQueue(*p,i%SizePQueue(*p)),val)){
            i++;
        }                                                       //find first matching element

        if(fx(ElmtPQueue(*p,i%SizePQueue(*p)),val)){
            for(;i<endTraversal;i++){
                ElmtPQueue(*p,i%SizePQueue(*p)) = ElmtPQueue(*p,(i+1)%SizePQueue(*p));
            }
            IdxTail(*p) = (IdxTail(*p)-1)%SizePQueue(*p);               //ser geser

            return true;
        }
    }                           //return true bila ada yg ter remove jika tidak false

    return false;
}

ElTypePQueue getElmtPQueue(PQueue p, int idx){
    return ElmtPQueue(p,(IdxHead(p)+idx)%SizePQueue(p));
}

void resizePQueue(PQueue* p){
    Queue(*p) = (ElTypePQueue*)realloc(Queue(*p),SizePQueue(*p)*2*sizeof(ElTypePQueue));
    SizePQueue(*p)*=2;
}

void destroyPQueue(PQueue* p){
    free(Queue(*p));
}

int lengthPQueue(PQueue p){
    if(IdxHead(p)<=IdxTail(p)){
        return IdxTail(p)-IdxHead(p)+1;
    } else {
        return IdxTail(p)+SizePQueue(p)-IdxHead(p)+1;
    }
}

void updateElmtPQueuePriority(PQueue* p, int amount){
    int i;
    for(i=0;i<lengthPQueue(*p);i++){
        ElTypePQueue* x = (ElTypePQueue*)(&(ElmtPQueue(*p,(IdxHead(*p)+i)%SizePQueue(*p))));
        GetPrio(*x) += amount;
    }
}