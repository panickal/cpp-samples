#include<gtest/gtest.h>

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

template<typename T>
void rotate_matrix(T &matrix, const int &n) {
    for (int i = 0; i < n/2; ++i) {
        for (int j = i; j < n-i-1; ++j) {
            swap(matrix[i][j], matrix[j][n-i-1]);
            swap(matrix[i][j], matrix[n-i-1][n-j-1]);
            swap(matrix[i][j], matrix[n-j-1][i]);            
        }
    }
}

TEST(rotate_matrix, tests) {
    constexpr int n = 30;
    int matrix[n][n];
    // Initializes the matrix with numbers 1, 2, 3...
    int data = 0;
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            matrix[i][j] = ++data;
        }
    }

    // Initializes the test matrix with numbers 91, 81, 71 etc after rotation...
    int test_matrix[n][n];
    int val = (n * n) - (n - 1);
    for (int i = 0; i < n; ++i) {
        int data = val + i;        
        for(int j = 0; j < n; ++j) {
            test_matrix[i][j] = data;
            data -= n;
        }
    }

    rotate_matrix(matrix, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ASSERT_EQ(matrix[i][j], test_matrix[i][j]);
        }
    }
}