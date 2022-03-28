#include <stdio.h>

void hanoi(int n, char start, char end, char intermediate) {
    if (n == 1) {
        printf("Move disc 1 from %c to %c\n", start, end);
        return;
    }
    hanoi(n-1, start, intermediate, end);
    printf("Move disc %d from %c to %c\n", n, start, end);
    hanoi(n-1, intermediate, end, start);
}

int main() {
    while(1) {
        int hanoi_discs;
        printf("Enter hanoi discs: ");
        scanf("%d", &hanoi_discs);
        if (hanoi_discs < 0)
            break;
        hanoi(hanoi_discs, 'A', 'C', 'B');
    }
}
