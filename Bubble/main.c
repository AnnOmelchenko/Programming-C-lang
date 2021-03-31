#include <stdio.h>
#include <errno.h>


int clear(char issue) {
    if (issue == '\n')
        return 0;
    else {
        while (issue != '\n')
            issue = getchar();

        return 1;
    }
}


float arrayElement(int i, char issue){
    float element;
    printf("\nEnter the elements in array [-1e6; 1e6]\narray[%d]: ", i + 1);
    do {
        errno = 0;
        scanf("%f", &element);
        issue = getchar();
        if (issue != '\n')
            printf("No symbols! Please, try again: ");
        else if (element < -1e6 || element > 1e6 || errno == ERANGE)
            printf("Incorrect input. Element must be in range[-1e6, 1e6] and float. Try again: \n");
        clear(issue);
    }while (issue != '\n' || element < -1e6 || element > 1e6 ||  errno == ERANGE);
    return element;
}

void arrayInput(float *array, int size, char issue) {
    int i;
        for (i = 0; i < size; i++)
            array[i] = arrayElement(i, issue);
}

    void sort(float *array, int num)
    {
        float temp;
        int i, j;
        for (i = 0; i < num - 1; i++)
        {
            for (j = i + 1; j < num; j++) {
                if (array[i] > array[j]) {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }


    int main(){
        int size;
        float array[100];
        char issue;
        do {
            printf("Enter quantity of elements in array [1; 100]:  ");
            do {
                scanf("%d", &size);
                issue = getchar();
                if (issue != '\n')
                    printf("No symbols and only integer! Please, try again: ");
                else if (size <= 0)
                    printf("Too small number. Please, try again: ");
                else if (size > 100)
                    printf("Too large number. Please, try again: ");
                clear(issue);
            } while (issue != '\n' || size > 100 || size <= 0);

            arrayInput(array, size, issue);

            sort(array, size);

            printf("\nSorted array: \n");
            int i;
            for (i = 0; i < size; i++)
                printf("%f\n", array[i]);

            printf("Press ENTER to continue, or enter any key to exit:  ");
        }while (getchar() == '\n');


        return 0;
}





















