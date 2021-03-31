#include <stdio.h>
#include <math.h>

int clear(char issue) {
    if (issue == '\n')
        return 0;
    else {
        while (issue != '\n')
            issue = getchar();

        return 1;
    }
}

double sinus(double arg, double eps){
    double sinus, sigma;
    int n = 1;
    sinus = sigma = arg;

    while (fabs(sigma) >= eps){
        sigma = sigma * (-pow(arg, 2.0) / ((n + 1) * (n + 2)));
        sinus += sigma;
        n += 2;
    }
    return sinus;
}

double enterValue(char array[], double min, double max){
    double x;
    char issue;
    printf(array);
    do {
        scanf("%lf", &x);
        issue = getchar();
        if (issue != '\n')
            printf("No symbols. Please, try again: ");
        else if (x > max)
            printf("Too large number! Please, try again: ");
        else if (x < min)
            printf("Too small number. Please, try again: ");

        clear(issue);
    }while (issue != '\n' || x > max || x < min);
    return x;
    }

double Calculation(double taylor, double math, double difference, double arg, double convert, double eps, double smth, double step){
    taylor = sinus(arg * convert, eps);
    math = sin(arg * convert);
    difference = fabs(taylor - math);
        printf("%.9lf     |        %.9lf          |         %.9lf             |      %0.9lf\n", smth,
               taylor, math, difference);
}

int main() {
double x1, x2, step, eps, arg, convert, taylor, math, difference;
char issue;

printf("Constructing Taylor series for Sine and Cosine\n\n");
do {
    do {
        x1 = enterValue("Enter x1 [-360; 360]: ", -360, 360);
        x2 = enterValue("Enter x2 [-360; 360]: ", -360, 360);

        if (x1 == x2) {
            printf("Incorrect. Please, try again.\n");
        }
    } while (x1 == x2);

    printf("Enter step (step > 0 and step < |x2 - x1|): ");
    do {
        scanf("%lf", &step);
        issue = getchar();
        if (issue != '\n')
            printf("No symbols. Please, try again: ");
        else if (step <= 0)
            printf("Too small number! Please, try again: ");
        else if (step > fabs(x2 - x1))
            printf("Too large number. Please, try again: ");

        clear(issue);
    } while (issue != '\n' || step > fabs(x2 - x1) || step <= 0);

    printf("Enter accuracy (0.0000001; 1): ");
    do {
        scanf("%lf", &eps);
        issue = getchar();
        if (issue != '\n')
            printf("No symbols. Please, try again: ");
        else if (eps >= 1)
            printf("Too large number! Please, try again: ");
        else if (eps <= 0.00000001)
            printf("Too small number. Please, try again: ");

        clear(issue);
    } while (issue != '\n' || eps >= 1 || eps <= 0.00000001);

    printf("\nArgument        |        sin(x)         |         sin(x_table)          |      Difference\n");
    arg = x1;
    convert = M_PI / 180;

    if (arg < x2 ) {
        while (arg < x2 - 1e-6) {
            Calculation(taylor, math, difference, arg, convert, eps, arg, step);
            arg += step;
        }
        Calculation(taylor, math, difference, arg, convert, eps, x2, step);
    } else if (arg > x2) {
        while (arg > x2 + 1e-6) {
            Calculation(taylor, math, difference, arg, convert, eps, arg, step);
            arg -= step;
        }
            Calculation(taylor, math, difference, arg, convert, eps, x2, step);
    }
    printf("\nPress Enter to continue or enter any key to exit: \n");

} while(getchar() == '\n');
return 0;
}
