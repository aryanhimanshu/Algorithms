#include <stdio.h>

int main() {

    int i, j, Temp, List[] = {6, 3, 0, 4, 8, 2, 5, 0, 1, 7};

    printf("List Before Sorting :\n");
    for (j = 0; j < 10; j++) {
        printf("%d ", List[j]);
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j <= i; j++) {
            if (List[j] > List[i]) {
                Temp = List[i];
                List[i] = List[j];
                List[j] = Temp;
            }
        }
    }
    printf("\nList Before Sorting :\n");
    for (j = 0; j < 10; j++) {
        printf("%d ", List[j]);
    }
   printf ("\n");
}
