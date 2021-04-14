#include <stdio.h>
#include <string.h>

int clear(char issue) {

    if (issue == '\n') {
        return 0;
    } else {
        while (issue != '\n') {
            issue = getchar();
        }
        return 1;
    }
}

int clear_1(char *array, int size){
    int c;

    if(strlen(array) < size - 1){
        return 1;
    }

    while ((c = getchar()) != EOF && c != '\n')
        continue;
    return c;
}

int sizeInput(){
    int size;
    char issue;

    printf("Enter quantity of strings range[2, 100]: ");

    do {
        (scanf("%i", &size));
        issue = getchar();
        if (issue != '\n'){
            printf("No symbols! Please, try again: ");
        }else if (size < 2 || size > 100){
            printf("Error, enter quantity again: ");
        }
        clear(issue);
    }while (issue != '\n' || size < 2 || size > 100);

    return size;
}

int main (){
    int i1, size;
    char *k;

    size = sizeInput();

    char arr[size][100];
    char *pointer[size];

    for (int i1 = 0; i1 < size; ++i1){
            printf("arr[%d] (Max length 100 symbols): ", i1 + 1);

            fgets(arr[i1],101, stdin);

            pointer[i1] = arr[i1];

            clear_1(pointer[i1], 101);
    }

    for(int a = 0; a != size; a++){
        for(int b = a + 1; b != size; b++){
            if(strlen(pointer[a]) > strlen(pointer[b])){
                k = pointer[a];
                pointer[a] = pointer[b];
                pointer[b] = k;
            }
        }
    }
    printf("Sorted array.\n");
    for(i1 = 0; i1 < size; ++i1){
        printf("arr[%d]=",i1+1);
        printf("%s\n",pointer[i1]);
    }
    return 0;
}