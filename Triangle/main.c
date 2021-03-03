#include <stdio.h>
#include <math.h>

double p(double, double, double);
double S(double, double, double, double);
double H(double, double, double, double);
double M(double, double, double);
double B(double, double, double, double);


int main() {

    printf("Triangle calculator\n");
    printf("Enter 3 sides:\n");

    double a, b, c;

    printf("A:");
    scanf("%lf", &a);
    if(getchar() != '\n' || a <= 0){
        printf("Error 1(a)");           //неправильно введена сторона А
        return 0;
    }

    printf("\nB:");
    scanf("%lf", &b);
    if(getchar() != '\n' || b <= 0){
        printf("Error 1(b)");             //неправильно введена сторона В
        return 0;
    }

    printf("\nC:");
    scanf("%lf", &c);
    if(getchar() != '\n' || c <= 0){
        printf("Error 1(c)");            //неправильно введена сторона С
        return 0;
    }

    if((a + b <= c) || (a + c <= b) || (b + c <= a)){    //Трикутника не існує
        printf("Error 2");
        return 0;
    }

    double P = p(a, b, c);

    printf("Square = %.3lf\n", S(a, b, c, P));
    printf("Height A = %.3lf\n", H(a, b, c, P));
    printf("Height B = %.3lf\n", H(b, a, c, P));
    printf("Height C = %.3lf\n", H(c, a, b, P));
    printf("Median A = %.3lf\n", M(a, b, c));
    printf("Median B = %.3lf\n", M(b, a, c));
    printf("Median C = %.3lf\n", M(c, b, a));
    printf("Bisector A = %.3lf\n", B(a, b, c, P));
    printf("Bisector B = %.3lf\n", B(b, a, c, P));
    printf("Bisector C = %.3lf\n", B(c, a, b, P));
    printf("Perimeter = %.3lf\n", (a + b + c));

    return 0;
}

double p(double a, double b, double c) {
    return (a + b + c) / 2.0;}

double S(double a, double b, double c, double p) {
    return sqrt(p * (p - a) * (p - b) * (p - c));}

double H(double a, double b, double c, double p) {
    return 2.0 * sqrt(p * (p - a) * (p - b) * (p - c)) / a;}

double M(double a, double b, double c) {
    return sqrt(2.0 * pow(b, 2.0) + 2.0 * pow(c, 2.0) - pow(a, 2.0)) / 2.0;}

double B(double a, double b, double c, double p) {
    return 2.0 * sqrt(b * c * p * (p - a)) / (b + c);}
