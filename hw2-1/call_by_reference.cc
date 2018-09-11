#include <stdio.h>

void square(double& dvar) {
    dvar = dvar * dvar;
}

int main() {
    double dvar = 0;
    scanf("%lf", &dvar);

    square(dvar);
    printf("%lf\n", dvar);
}
