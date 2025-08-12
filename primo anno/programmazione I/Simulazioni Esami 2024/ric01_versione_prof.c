#include <stdio.h>
#include <stdbool.h>

int e2R(const size_t aLen, const int a[], const size_t bLen, const int b[], 
        const size_t i)
{
    if (i>=aLen && i>=bLen) {
        return 0;
    }
    else if (i>=aLen) {
        return b[i]*b[i] + e2R(aLen, a, bLen, b, i+1);
    }
    else if (i>=bLen) {
        return a[i]*a[i] + e2R(aLen, a, bLen, b, i+1);
    }
    else {
        return a[i]*b[i] + e2R(aLen, a, bLen, b, i+1);
    }
}

int e2(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
    return e2R(aLen, a, bLen, b, 0);
}