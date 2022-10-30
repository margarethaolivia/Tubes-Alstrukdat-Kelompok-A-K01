#include "../stack.h"
#include "../simulator.h"
#include <stdio.h>
int main()
{
    Stack s;
    CreateEmpty(&s);

    simulator x;
    createSim(&x);

    boolean a = IsEmpty(s);
    boolean b = IsFull(s);
    Push(&s, x);
    Pop(&s, &x);

    return 0;
}