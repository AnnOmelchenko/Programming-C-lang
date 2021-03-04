#include <stdio.h>
#include <math.h>

int clear(char issue){
    if (issue == '\n'){
        return 0;
    } else {
        while (issue != '\n'){
            issue = getchar();
        }
        return 1;
    }
}

void positiveCase(float q, float d, float p, float a){
    float u, v, u1;
    u1 = (-q / 2.0 + sqrt(d));
    if(u1 >= 0){
        u = pow(u1,1.0 / 3.0);
    } else {
        u = -pow(fabsf(u1),1.0 / 3.0);
    }

    v = -p / (3.0 * u);

    float x1, x2, x3;
    float y1, y2, y3;

    y1 = u + v;
    y2 = -(u+v) / 2.0;
    y3 = sqrt(3.0)*(u-v)/2.0;

    x1 = y1 - a / 3.0;
    x2 = y2 - a / 3.0;
    x3 = y2 - a / 3.0;

    printf("The equation has one real root, and two complex \n");

    printf("x1 = %f \n", x1);
    printf("x2 = %f + %f * i \n", x2, y3);
    printf("x2 = %f - %f * i \n", x3, y3);
}

void nullCase(float p, float q, float a){
    float x1, x2, x3;
    float y1, y2, y3;

    y1 = 3.0 * q / p;
    y2 = -(3.0 * q) / (2.0 * p);
    y3 = y2;

    x1 = y1 - a / 3.0;
    x2 = y2 - a / 3.0;
    x3 = y3 - a / 3.0;

    printf("The equation has three real roots, two of them are equal \n");

    printf("x1 = %f \n", x1);
    printf("x2 = %f \n", x2);
    printf("x3 = %f \n", x3);
}

void negativeCase(float p, float q, float a){
    float r, o;
    float x1, x2, x3;
    float y1, y2, y3;

    r = sqrt(-pow(p,3.0) / 27.0);
    o = acos(-(q / (2.0 * r)));

    y1 = 2.0 * fabs(pow(r,1.0 / 3.0)) * cos(o / 3.0);
    y2 = 2.0 * fabs(pow(r,1.0 / 3.0)) * cos((o + 2.0 * M_PI) / 3.0);
    y3 = 2.0 * fabs(pow(r,1.0 / 3.0)) * cos((o + 4.0 * M_PI) / 3.0);

    x1 = y1 - a / 3.0;
    x2 = y2 - a / 3.0;
    x3 = y3 - a / 3.0;

    printf("The equation has three different real roots. It can be calculated only approximate \n");

    printf("x1 = %f \n", x1);
    printf("x2 = %f \n", x2);
    printf("x3 = %f \n", x3);
}

int main() {
    double a, b, c;
    double p, q, d;
    char issue;
    double result;

        printf("Cubic equation calculator\n\n");
        do {
            printf("Enter a: ");
            do {
                scanf("%lf", &a);
                issue = getchar();
                if (issue != '\n') {
                    printf("No symbols! Please, try again:  ");
                } else if (a > 99999){
                    printf("Too large number(-99999; 99999). Try again:  ");
                }  else if (a < -99999) {
                    printf("Too small number(-99999; 99999). Try again:  ");
                }
                clear(issue);
            } while (issue != '\n' || a > 99999 || a < -99999);

            printf("Enter b: ");
            do {
                scanf("%lf", &b);
                issue = getchar();
                if (issue != '\n') {
                    printf("No symbols! Please, try again:  ");
                }else if (b > 99999){
                    printf("Too large number(-99999; 99999). Try again:  ");
                }  else if (b < -99999) {
                    printf("Too small number(-99999; 99999). Try again:  ");
                }
                clear(issue);
            } while (issue != '\n' || b > 99999 || b < -99999);

            printf("Enter c: ");
            do {
                scanf("%lf", &c);
                issue = getchar();
                if (issue != '\n') {
                    printf("No symbols! Please, try again:  ");
                }else if (c > 99999){
                    printf("Too large number(-99999; 99999). Try again:  ");
                }  else if (c < -99999) {
                    printf("Too small number(-99999; 99999). Try again:  ");
                }
                clear(issue);
            } while (issue != '\n' || c > 99999 || c < -99999);

            if (a == 0 && b == 0 && c != 0){
                printf("\nResult: \n\n x = %lf\n", result = -pow(c, 1 / 3.0) );
                printf("Press ENTER to continue or enter any key to exit:");
                continue;
            } else if (a == 0 && b == 0 && c == 0){
                printf("\nResult: \n\n x = %lf\n", result = 0);
                printf("Press ENTER to continue or enter any key to exit:");
                continue;
            }


        printf("x^3 + %.1fx^2 + %.1fx + %.1f = 0\n", a, b, c);

        p = b - pow(a, 2.0) / 3.0;
        q = 2.0 * pow(a, 3.0) / 27.0 - a * b / 3.0 + c;
        d = pow(p, 3.0) / 27.0 + pow(q, 2.0) / 4.0;

        if (d > 0){
            positiveCase(q, d, p, a);
        } else if ( d == 0){
            nullCase(p, q, a);
        } else if ( d < 0){
            negativeCase(p, q, a);
        }
        printf("Press ENTER to continue or enter any key to exit:");
    }while (getchar() == '\n');
    return 0;
}
