#include "ai.h"

#include <stdint.h>
#include <openssl/rand.h>

char *AIAdder_init(AIAdder *adder) {
    uint64_t idx;
    int64_t p[4];

    /* Initialize training data */

    for (idx = 0; idx < AI_T_COUNT; ++idx) {
        if (RAND_bytes((unsigned char *)adder->t[idx], sizeof(adder->t[idx])) !=
            1)
            return "Failed to initialize training data.";

        adder->t[idx][0] %= 512;
        adder->t[idx][1] %= 512;
        adder->t[idx][2] = adder->t[idx][0] + adder->t[idx][1];
    }

    /* Initialize parameters */

    if (RAND_bytes((unsigned char *)p, sizeof(p)) != 1)
        return "Failined initializing parameters.";

    adder->p0 = (double)p[0] / (double)INT64_MAX * 1024.0f;
    adder->p1 = (double)p[1] / (double)INT64_MAX * 1024.0f;
    adder->b0 = (double)p[2] / (double)INT64_MAX * 1024.0f;
    adder->b1 = (double)p[3] / (double)INT64_MAX * 1024.0f;

    return NULL;
}

void AIAdder_print(const AIAdder adder) {
    printf("p0, p1 = %.15f, %.15f | b0, b1 = %.15f, %.15f\n", adder.p0,
           adder.p1, adder.b0, adder.b1);
}

double AIAdder_learn(AIAdder *adder) {
    uint64_t idx;

    double loss = 0.0;

    double grad_p0 = 0.0, grad_p1 = 0.0;
    double grad_b0 = 0.0, grad_b1 = 0.0;

    for (idx = 0; idx < AI_T_COUNT; ++idx) {
        int64_t a = adder->t[idx][0], b = adder->t[idx][1];
        int64_t ex = adder->t[idx][2]; /* expected output */

        double ap = (double)a * adder->p0 + adder->b0;
        double bp = (double)b * adder->p1 + adder->b1;

        double prediction = ap + bp;
        double error      = prediction - (double)ex;

        grad_p0 += 2 * error * (double)a;
        grad_p1 += 2 * error * (double)b;
        grad_b0 += 2 * error;
        grad_b1 += 2 * error;

        loss += error * error;
    }

    /* Gradient normalization */

    grad_p0 /= AI_T_COUNT;
    grad_p1 /= AI_T_COUNT;
    grad_b0 /= AI_T_COUNT;
    grad_b1 /= AI_T_COUNT;

    /* Learn (update parameters) */

    adder->p0 -= AI_LEARNING_RATE * grad_p0;
    adder->p1 -= AI_LEARNING_RATE * grad_p1;
    adder->b0 -= AI_LEARNING_RATE * grad_b0;
    adder->b1 -= AI_LEARNING_RATE * grad_b1;

    return loss / AI_T_COUNT;
}

double AIAdder_apply(const AIAdder adder, const double a, const double b) {
    return (a * adder.p0 + adder.b0) + (b * adder.p1 + adder.b1);
}
