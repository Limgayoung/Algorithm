#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
#define HeapNum 100002

typedef struct element {
    int key;
}e;

struct heap {
    e heap[HeapNum];
    int heapSize;
};

void push(int x, heap *H) {
    int id = (H->heapSize)+1;

    while (id != 1 && H->heap[id / 2].key < x) { //비어있지 않고, 부모가 자식보다 작을 동안
        H->heap[id] = H->heap[id / 2]; //바꾸기
        id /= 2;
    }

    H->heap[id].key = x;
    H->heapSize++;
}

int pop(heap* H) {
    int top = H->heap[1].key; //반환할 루트 값 (최대값)

    e temp = H->heap[H->heapSize]; //빈 루트에 마지막 원소 넣기

    int parent = 1, child = 2;

    while (H->heapSize >= child) { 
        
        if (child < H->heapSize && H->heap[child].key < H->heap[child+1].key) { 
            //왼쪽 자식이 오른쪽 자식보다 큰 경우 child ++ 을 해서 오른쪽 자식으로 이동하기
            child++;
        }
        if (temp.key > H->heap[child].key) { //temp가 child보다 크면 그만 바꿔도 됨
            break;
        }
        //아닌 경우에는 바꿔줘야 함
        H->heap[parent] = H->heap[child];
        parent = child;
        child *= 2;
    }

    H->heap[parent] = temp;
    (H->heapSize)--;

    return top;

}


int main() {
    int N;
    int i, num;
    

    heap H;
    H.heapSize = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &num);

        if (num == 0) { //가장 큰 값 출력하기
            if (H.heapSize == 0) printf("0\n");
            else {
                printf("%d\n", pop(&H));
            }
        }
        else { //입력하기
            push(num, &H);
        }

    }

    return 0;
}
