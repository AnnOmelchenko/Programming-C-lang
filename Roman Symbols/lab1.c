#include <stdio.h>

int roman(int, int, char);

int main() {
	printf("Введите число от 1 до 1000: ");

	int num;
	scanf("%u", &num);

	char symbol;
	scanf("%c", &symbol);

	if(num > 0 && num <= 1000 && symbol == '\n'){
		num = roman(num, 1000, 'M');
		num = roman(num, 500, 'D');
		num = roman(num, 100, 'C');
		num = roman(num, 50, 'L');
		num = roman(num, 10, 'X');
		num = roman(num, 5, 'V');
		num = roman(num, 1, 'I');
		putchar('\n');
	}
	else{
		printf("Число не верно\n");
	}
    return 0;
}


int roman(int number, int substructer, char ch){
	while(number >= substructer){
		number -= substructer;
		putchar(ch);
	}
return number;
}
