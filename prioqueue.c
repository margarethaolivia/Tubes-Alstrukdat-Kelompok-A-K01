#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

void createPQueue(PQueue* p, int nMax){
    Queue(*p) = (ElTypePQueue*)malloc(sizeof(ElTypePQueue)*nMax);
    IdxHead(*p) = IDX_UNDEFF;
    IdxTail(*p) = IDX_UNDEFF; //blablabla init
    Size(*p) = nMax;
    Length(*p) = 0;

}

boolean isEmpty(PQueue p){
    return IdxHead(p)==IDX_UNDEFF; //is empty
}

boolean isFull(PQueue p){
    if(IdxTail(p)>IdxHead(p)){
        return IdxTail(p)==(Size(p)-1)&&IdxHead(p)==0; //is full
    } else {
        return (IdxHead(p)-IdxTail(p))==1;
    }
}

void enqueue(PQueue* p, ElTypePQueue val){
    if(isEmpty(*p)){
        Elmt(*p,0) = val;
        IdxTail(*p) = 0;            //is empty? enqu
        IdxHead(*p) = 0;
        Length(*p) = 1;
    }
    else if(!isFull(*p)){
        int startTraversal = IdxHead(*p);
        int endTraversal = IdxTail(*p);
        if(endTraversal<startTraversal){endTraversal+=Size(*p);}

        int i = startTraversal;
        while(i<=endTraversal&&GetPrio(Elmt(*p,i%Size(*p)))<=GetPrio(val)){
            i++;
        }
        if(GetPrio(Elmt(*p,i%Size(*p)))==GetPrio(val)){i++;}   //sortby prio

        int j;
        for(j=endTraversal+1;j>i;j--){
            Elmt(*p,j%Size(*p)) = Elmt(*p,(j-1)%Size(*p));      //ser geser
        }

        Elmt(*p,i%Size(*p)) = val;
        
        IdxTail(*p) = (endTraversal+1)%Size(*p);
        Length(*p)++;
    }
    else if(isFull(*p)){
        resize(p);                  //full? resize
        enqueue(p,val);
    }
}

void dequeue(PQueue* p, ElTypePQueue* val){
    if(!isEmpty(*p)){
        *val = Head(*p);
        
        IdxHead(*p) = (IdxHead(*p)+1)%Size(*p);
        if(IdxHead(*p)==(IdxTail(*p)+1)%Size(*p)){      //pop head??
            IdxHead(*p)=IDX_UNDEFF;
            IdxTail(*p)=IDX_UNDEFF;
        }
        
        Length(*p)--;
    }
}

boolean removeFromQueue(PQueue* p, lambdaPQ fx, CompareType val){
    if(!isEmpty(*p)){
        int startTraversal = IdxHead(*p);
        int endTraversal = IdxTail(*p);
        if(endTraversal<startTraversal){endTraversal+=Size(*p);}

        int i = startTraversal;
        while(i<endTraversal&&!fx(Elmt(*p,i%Size(*p)),val)){
            i++;
        }                                                       //find first matching element

        if(fx(Elmt(*p,i%Size(*p)),val)){
            for(;i<endTraversal;i++){
                Elmt(*p,i%Size(*p)) = Elmt(*p,(i+1)%Size(*p));
            }
            IdxTail(*p) = (IdxTail(*p)-1)%Size(*p);               //ser geser
            Length(*p)--;

            return true;
        }
    }                           //return true bila ada yg ter remove jika tidak false

    return false;
}

ElTypePQueue getElmt(PQueue p, int idx){
    return Elmt(p,(IdxHead(p)+idx)%Size(p));
}

ElTypePQueue* getElmtRef(PQueue* p, int idx){
    return &(Elmt(*p,(IdxHead(*p)+idx)%Size(*p)));
}

void resize(PQueue* p){
    Queue(*p) = (ElTypePQueue*)realloc(Queue(*p),Size(*p)*2*sizeof(ElTypePQueue));
    Size(*p)*=2;
}

void destroy(PQueue* p){
    free(Queue(*p));
}