#include <stdio.h>
#include <math.h>


        double root(double det, double y, double x, double k, double eps){
            while (fabs(det) > eps){
                det = (((x / pow (y, k - 1.0)) - y) / k);
                y = y + det;
            }
            return y;
        }

        int check(char issue) {
            if (issue == '\n') {
                return 0;
            } else {
                while (issue != '\n') {
                    issue = getchar();
                }
                return 1;
            }
        }

        int main() {
            double x, k, eps, result;
            char issue;
            do {
                printf("Root calculator\n\n");
                printf("Enter accuracy (from 0.00000001 to 1):  ");
                do {
                    scanf("%lf", &eps);
                    issue = getchar();
                    if (issue != '\n') {
                        printf("No symbols! Please, try again: ");
                    } else if (eps < 0.00000001 || eps >= 1) {
                        printf("Incorrect (for example 0.00001). Try again: ");
                    }
                    check(issue);
                } while (issue != '\n' || eps < 0.00000001 || eps >= 1);

                printf("Enter the index of the root (K can't be 0, less than -1000 or more than 1000): ");
                do {
                    scanf("%lf", &k);
                    issue = getchar();
                    if (issue != '\n') {
                        printf("No symbols! Please, try again:  ");
                    }
                    else if (k == 0 || k < -1000 || k > 1000) {
                        printf("Incorrect. Please, try again: ");
                    }
                    check(issue);
                } while (issue != '\n' || k == 0 || k < -1000 || k > 1000);

                if (k > 0 && (int) k % 2 == 0) {
                    printf("Enter X (X can't be less than 0):  ");
                    do {
                        scanf("%lf", &x);
                        issue = getchar();
                        if (issue != '\n') {
                            printf("No symbols! Please, try again: ");
                        } else if (x < 0) {
                            printf("X can't be less than 0. Try again: ");
                        }
                        check(issue);
                    } while (issue != '\n' || x <= 0);
                    result = root(1.0, 1.0, x, k, eps);
                } else if (k > 0 && (int) k % 2 != 0) {
                    printf("Enter X:  ");
                    do {
                        scanf("%lf", &x);
                        issue = getchar();
                        if (issue != '\n') {
                            printf("No symbols! Please, try again: ");
                        }
                        check(issue);
                    } while (issue != '\n');
                    result = root(1.0, 1.0, x, k, eps);
                } else if (k < 0 && (int) k % 2 == 0) {
                    printf("Enter X (x > 0):  ");
                    do {
                        scanf("%lf", &x);
                        issue = getchar();
                        if (issue != '\n') {
                            printf("No symbols! Please, try again: ");
                        } else if (x <= 0) {
                            printf("X can't be 0 or less than 0. Try again: ");
                        }
                        check(issue);
                    } while (issue != '\n' || x <= 0);
                    result = 1.0 / root(1.0, 1.0, x, fabs(k), eps);
                } else if (k < 0 && (int) k % 2 != 0) {
                    printf("Enter X (X can't be 0):  ");
                    do {
                        scanf("%lf", &x);
                        issue = getchar();
                        if (issue != '\n') {
                            printf("No symbols! Please, try again: ");
                        } else if (x == 0) {
                            printf("X can't be 0. Try again:  ");
                        }
                        check(issue);
                    } while (issue != '\n' || x == 0);
                    result = 1.0 / root(1.0, 1.0, fabs(x), fabs(k), eps) * (fabs(x) / x);
                }
                printf("%lf", result);
                printf("\nPress Enter to continue or enter any key to exit: \n");
            } while (getchar() == '\n');
            return 0;
        }



