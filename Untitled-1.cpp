#include <iostream>
#include <vector>
using namespace std;
class NQueens {
private:
    int n;
    int count;
    vector<int> board;

    bool isSafe(int row, int col) {
        for (int i = 0; i < col; i++) {
            if (board[i] == row || 
                board[i] - i == row - col || 
                board[i] + i == row + col) {
                return false;
            }
        }
        return true;
    }

    void solveNQueensUtil(int col) {
        if (col == n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col)) {
                board[col] = row;
                solveNQueensUtil(col + 1);
            }
        }
    }

public:
    NQueens(int size) : n(size), count(0), board(size, -1) {}

    int solveNQueens() {
        solveNQueensUtil(0);
        return count;
    }
};

int main() {
    int n;
    cout << "Golemina na tablata ";
    cin >> n;

    NQueens nQueens(n);
    int solutions = nQueens.solveNQueens();

    cout << solutions << std::endl;

    return 0;
}
