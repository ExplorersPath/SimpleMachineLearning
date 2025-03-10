#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float sigmoidf (float x){
    return 1.0f / (1.0f + expf(-x));
}

// OR-gate
float train[][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
};
#define TRAIN_COUNT (sizeof(train)/sizeof(train[0]))

// AND-gate
float train2[][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 1},
};
#define TRAIN2_COUNT (sizeof(train2)/sizeof(train2[0]))

float rand_float(void){
    return (float) rand() / (float) RAND_MAX;
}

float cost(float w1, float w2, float b){
    float result = 0.0f;
    for(size_t i = 0; i < TRAIN2_COUNT; i++){
        float x1 = train2[i][0];
        float x2 = train2[i][1];
        float y = sigmoidf(x1 * w1 + x2 * w2 + b);
        float d = y - train2[i][2];
        result += d*d;
    }
    result /= TRAIN2_COUNT;
    return result;
}

int main(void){
    srand(time(0));
    rand();
    rand();

    float w1 = rand_float();
    float w2 = rand_float();
    float b = rand_float();
    
    float eps = 1e-1;
    float rate = 1e-1;

    for(size_t i = 0; i < 100000; i++){
        float c = cost(w1, w2, b);
        float dw1 = (cost(w1 + eps, w2, b) - c) / eps;
        float dw2 = (cost(w1, w2 + eps, b) - c) / eps;
        float db =  (cost(w1, w2, b + eps) - c) / eps;

        w1 -= rate * dw1;
        w2 -= rate * dw2;
        b -= rate * db;
    }

    printf("w1: %f, w2: %f, b: %f, cost: %f\n", w1, w2, b, cost(w1, w2, b));
}