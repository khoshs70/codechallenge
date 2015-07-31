/*
Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees Can you do this in place?
*/
/*
不要想着整行整列复制,逐个元素复制会比较好
*/
#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(int *m, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){     
            std::cout << std::setfill('0') << std::setw(2);
            cout << m[count++] << " ";
        }
        cout << std::endl;
    }
}

void cci_1_6() {
    const int n = 5;
    int m[n][n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            m[i][j] = count++;
            std::cout << std::setfill('0') << std::setw(2);
            cout << m[i][j] << " ";
        }
        cout << std::endl;
    }
    cout << "\n\n";    
    int loop = n / 2;
    int start = 0;
    int end = n;
    
    for (int j = 0; j < loop; j++) {        
        for (int i = start; i < end-1; i++) {
            int offset = i - start;
            // save top
            int top = m[start][i];
            // left->top
            m[start][i] = m[end - offset - 1][start];
            // bottom -> left
            m[end - offset - 1][start] = m[end - 1][end - offset - 1];
            // right - > bottom
            m[end - 1][end - offset - 1] = m[i][end - 1];
            // top -> right
            m[i][end - 1] = top;
        }        
        //printMatrix((int*)m, n);
        //cout << "\n";
        start++; end--;
    }
    printMatrix((int*)m, n);
    
 }

