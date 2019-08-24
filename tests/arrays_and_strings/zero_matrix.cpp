#include<gtest/gtest.h>

template<typename T>
void zero_matrix(T &matrix, const int &m, const int &n) {
    std::vector<bool> rows(m, false);
    std::vector<bool> columns(n, false);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(matrix[i][j] == 0) {
                rows[i] = true;
                columns[j] = true;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(rows[i] == true || columns[j] == true) {
                matrix[i][j] = 0;
            }
        }
    }
}

template<typename T>
void zero_matrix_space(T &matrix, const int &m, const int &n) {
    bool row_has_zero = false;
    bool column_has_zero = false;
    
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
            row_has_zero = true;
        }
    }

    for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
            column_has_zero = true;
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (row_has_zero == true) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }

    if (column_has_zero == true) {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }
}

TEST(zero_matrix, tests) {
    constexpr int M = 10;
    constexpr int N = 10;
    int matrix[M][N];

    // Initializes the matrix with numbers 1, 2, 3...
    int data = 0;
    for (int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            matrix[i][j] = ++data;
        }
    }
    matrix[0][2] = 0;
    matrix[3][5] = 0;
    matrix[6][1] = 0;
    matrix[9][8] = 0;

    int matrix_space[M][N];
    memcpy(matrix_space, matrix, sizeof(matrix));

    zero_matrix(matrix, M, N);
    zero_matrix_space(matrix_space, M, N);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            ASSERT_EQ(matrix[i][j], matrix_space[i][j]);
        }
    }
}