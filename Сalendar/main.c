#include <stdio.h>


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

        int High(int year) {
                return ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
        }

        int n(int month, int year) {
            if (month > 2) {
                return 0;
            } else if (month <= 2 && High(year) == 1) {
                return 1;
            } else if (month <= 2 && High(year) == 0) {
                return 2;
            }
        }

        int day(int date, int month, int year, int n) {
                return ((int)(365.25 * year) + (int)(30.56 * month) + date + n) % 7;
        }

        int check_day(int date, char issue) {
            if (issue != '\n' || date > 31 || date <= 0) {
                return 1;
            } else {
                return 0;
            }
        }

        int check_month(int month, char issue) {
            if (issue != '\n' || month <= 0 || month > 12) {
                return 1;
            } else {
                return 0;
            }
        }

        int check_year(int year, char issue) {
            if (issue != '\n' || year < 1918|| year >2099) {
                return 1;
            } else {
                return 0;
            }
        }

        int final_output(int date, int month, int year) {
            if ((month == 4 || month == 6 || month == 9 || month == 11) && date == 31) {
                printf("This month only 30 days. Please, try again.\n");
                return 1;
            } else if (month == 2 && (date == 30 || date == 31 || date == 29 ) && !High(year)) {
                printf("This month only 28 days. Please, try again.\n");
                return 1;
            } else if (month == 2 && (date == 30 || date == 31) && High(year)) {
                printf("This month only 29 days. Please, try again.\n");
                return 1;
            } else {
                return 0;
            }
        }



        int main() {
            int date, month, year;
            char issue;
            printf("Day of week calculator\n\n");
            do {
                printf("Enter day: ");
                do {
                    scanf("%d", &date);
                    issue = getchar();
                    if (issue != '\n') {
                        printf("No symbols! Please, try again:  ");
                    } else if (date <= 0) {
                        printf("Date can't be 0 or less than 0. Try again:  ");
                    } else if (date > 31) {
                        printf("Too large number. Try again:  ");
                    }
                    check(issue);
                } while (check_day(date, issue));

                printf("Enter month: ");
                do {
                    scanf("%d", &month);
                    issue = getchar();
                    if (issue != '\n') {
                        printf("No symbols! Please, try again:  ");
                    } else if (month <= 0) {
                        printf("Month can't be 0 or less than 0. Try again:  ");
                    } else if (month > 12) {
                        printf("Too large number. Try again:  ");
                    }
                    check(issue);
                } while (check_month(month, issue));

                printf("Enter year: ");
                do {
                    scanf("%d", &year);
                    issue = getchar();
                    if (issue != '\n') {
                        printf("No symbols! Please, try again:  ");
                    } else if (year < 1918) {
                        printf("This program count new calendar style (from 1918). Try again:  ");
                    } else if (year > 2099) {
                        printf("Too large, enter less than 2100. Try again:  ");
                    }
                } while (check_year(year, issue));

                if (final_output(date, month, year) == 0) {
                    printf("Your date is %d.%d.%d and it's  ", date, month, year);
                    switch (day(date, month, year, n(month, year))) {
                        case 0:
                            printf("Monday!");
                            break;
                        case 1:
                            printf("Tuesday!");
                            break;
                        case 2:
                            printf("Wednesday!");
                            break;
                        case 3:
                            printf("Thursday!");
                            break;
                        case 4:
                            printf("Friday!");
                            break;
                        case 5:
                            printf("Saturday!");
                            break;
                        case 6:
                            printf("Sunday!");
                    }
                }
                printf("\n\nPress ENTER to continue, or enter any key to exit. \n");
            }while (getchar() == '\n');
            return 0;
        }