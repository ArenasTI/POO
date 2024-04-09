#include <stdio.h>
int main()

{
    int num;

    printf ("Ingrese un numero entero: ");
    scanf ("%d", & num);

    while (num != 1) {
        printf("%d ", num);

        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = num * 3 + 1;
        }
    }

    printf("%d\n", num);

    return 0;
}
