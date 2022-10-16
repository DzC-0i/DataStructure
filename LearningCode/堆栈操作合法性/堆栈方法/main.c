#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef char ElementData;
struct Node {
    ElementData Data[MaxSize];
    int Top;
    int Max;
};
typedef struct Node* PtrToNode;
typedef PtrToNode List;
int isFull(List L) {
    return L->Top == L->Max - 1;
}
int isEmpty(List L) {
    return L->Top == -1;
}
int Push(List L, ElementData X) {
    if (isFull(L)) return 0;
    L->Data[++L->Top] = X;
    return 1;
}
int Pop(List L) {
    if (isEmpty(L)) return 0;
    return L->Data[L->Top--];
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    List L = (List)malloc(sizeof(struct Node));
    L->Max = m;
    L->Top = -1;
    char ch;
    for (int i = 0;i < n;i++) {
        int flg = 1;
        while ((ch = getchar()) != '\n') {
            if (!flg) continue;
            if (ch == 'S') {
                if (!Push(L, 'S')) { flg = 0; }
            }
            if (ch == 'X') {
                if (!Pop(L)) { flg = 0; }
            }
        }
        if (flg) {
            if (L->Top == -1) printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
        L->Top = -1;
    }
    return 0;
}