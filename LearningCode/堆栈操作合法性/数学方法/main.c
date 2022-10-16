#include<stdio.h>
/*
假设以S和X分别表示入栈和出栈操作。如果根据一个仅由S和X构成的序列，对一个空堆栈进行操作，相应操作均可行（如没有出现删除时栈空）
且最后状态也是栈空，则称该序列是合法的堆栈操作序列。请编写程序，输入S和X序列，判断该序列是否合法。
@输入第一行给出两个正整数N和M，其中N是待测序列的个数，M（≤50）是堆栈的最大容量。随后N行，每行中给出一个仅由S和X构成的序列。
序列保证不为空，且长度不超过100。
@对每个序列，在一行中输出YES如果该序列是合法的堆栈操作序列，或NO如果不是。
##
4 10
SSSXXSXXSX
SSSXXSXXS
SSSSSSSSSSXSSXXXXXXXXXXX
SSSXXSXXX
@#
YES
NO
NO
NO
*/
int main() {
    int n, m;
    char ch;
    scanf("%d %d\n", &n, &m);
    for (int i = 0;i < n;i++) {
        int sum = 0, flg = 1;
        while ((ch = getchar()) != '\n') {
            if (ch == 'S') sum++;
            if (ch == 'X') sum--;
            if (sum<0 || sum>m) flg = 0;
        }
        if (flg) {
            if (sum == 0) printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
    }
    return 0;
}