#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRAIN_COUNT (sizeof(train)/sizeof(train[0]))
float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};

float rand_float(void){
    return (float) rand() / (float) RAND_MAX;
}

float cost(float w){
    float result = 0.0f;
    for(size_t i = 0; i < TRAIN_COUNT; i++){
        float x = train[i][0];
        float y = x * w;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= TRAIN_COUNT;
    return result;
}

int main(){
    srand(time(0));
    rand();
    rand();

    // y = x*w
    float w = rand_float() * 10.0f;

    float eps = 1e-3;
    float rate = 1e-3;

    for(size_t i = 0; i < 1000; i++){
        float dcost = (cost(w + eps) - cost(w)) / eps;

        w -= rate * dcost;
    }

    printf("w: %f, cost: %f\n", w, cost(w));

    return 0;
}