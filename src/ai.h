#ifndef _AI_H
#define _AI_H

#include <stdint.h>

#ifndef NULL
#define NULL ((void *)0)
#endif /* NULL */

#define AI_T_COUNT       8196
#define AI_LEARNING_RATE 1e-5

typedef struct {
    double p0, p1;
    double b0, b1;
    int16_t t[AI_T_COUNT][3];
} AIAdder;

char *AIAdder_init(AIAdder *adder);
void AIAdder_print(const AIAdder adder);
double AIAdder_learn(AIAdder *adder);
double AIAdder_apply(const AIAdder adder, const double a, const double b);

#endif /* _AI_H */
