#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ai.h"
#include "main.h"

int main(const int argc, const char *const argv[]) {
    double a, b;
    uint64_t idx;
    double loss;

    AIAdder adder;

    if (argc < 3) {
        fprintf(stderr,
                "Enterprise addition of numbers in C.\nUsage: %s <number> "
                "<number>\n",
                argv[0]);
        return 1;
    }

    a = atof(argv[1]);
    b = atof(argv[2]);

    AIAdder_init(&adder);

    AIAdder_print(adder);

    for (idx = 0; idx < AI_T_COUNT; ++idx)
        printf("%d + %d = %d\n", adder.t[idx][0], adder.t[idx][1],
               adder.t[idx][2]);

    idx = 0;

    do {
        loss = AIAdder_learn(&adder);
        printf("Epoch %lu with loss %.15lf: ", idx, loss);
        AIAdder_print(adder);
        ++idx;
    } while (loss > 0.001);

    puts("Extra learning passes...");

    for (idx = 0; idx < EPOCHS; ++idx) {
        loss = AIAdder_learn(&adder);
        printf("[%.15lf%%] Epoch %lu with loss %.15lf: ",
               (double)(idx + 1) / EPOCHS * 100.0f, idx, loss);
        AIAdder_print(adder);
    }

    printf("%.15lf + %.15lf = ~%.15lf\n", a, b, AIAdder_apply(adder, a, b));

    return 0;
}
