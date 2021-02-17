#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double sampleStddev(int count, ...);

int main(void) {
    printf("%f\n", sampleStddev(4, 25.0, 27.3, 26.9, 25.7));

    return 0;
}

double sampleStddev(int count, ...) {
    double sum = 0;

    va_list args1;
    va_start(args1, count);
    va_list args2;
    va_copy(args2, args1);

    for (int i = 0; i < count; ++i) {
        double num = va_arg(args1, double);
        sum += num;
    }

    va_end(args1);

    double mean = sum / count;
    double sumSqDiff = 0;

    for (int i = 0; i < count; ++i) {
        double num = va_arg(args2, double);
        sumSqDiff += (num - mean) * (num - mean);
    }

    va_end(args2);

    return sqrt(sumSqDiff / count);
}