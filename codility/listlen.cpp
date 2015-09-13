/*
list length
*/
struct IntList {
    int value;
    struct IntList * next;
};

static int solution(IntList * L) {
    // write your code in C++11
    int len = 1;
    while (L) {
        L = L->next;
        len++;
    }
    return len;
}

