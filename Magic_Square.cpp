#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int N;
	std::cout << "Enter the value you want for the N x N matrix\n\n";
	std::cin >> N;

	int TotalElements = N * N;
	std::cout << "The total ammount of numbers your will need to enter is " << TotalElements << "\n";
	std::cout << "enter your numbers: \n";

	//Check 1: check if perosn put N^2 numbers in
	vector<int> numbers (TotalElements);

	for (int i = 0; i < TotalElements; i++) {
		cin >> numbers[i];
	}
	// END check 1



	//Check 2: No repeating #
	bool numcheck = false;

	for (int i = 0; i < TotalElements; i++) {
		for (int j = i+1; j < TotalElements; j++) {
			if (i == j) {
				std::cout << "Illegal repeating #" << endl;
				numcheck = true;
				break;
			}
			if (numcheck) {
				break;
			}
		}
	}
	
	if (!numcheck) {
        std::cout << "No repeating #, Legal" << endl;
	}
    std::cout << "\n";
	// END check 2



	//CHeck 3: Diag Col Row sums
    int grid[N][N];  
    int index = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = numbers[index++];
        }
    }




    int magicConstant = N * (N * N + 1) / 2;  
    // total of what the column can be

    std::cout << "\nYour square is:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(4) << grid[i][j];  
        }
        std::cout << "\n";  

    }
    //output for the square^^^


    for (int i = 0; i < N; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += grid[i][j];
        }
        if (rowSum != magicConstant) {
            cout << "The numbers do not form a magic square." << endl;
            return 0;
        }
    }//sum of rows^^

    for (int j = 0; j < N; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++) {
            colSum += grid[i][j];
        }
        if (colSum != magicConstant) {
            cout << "The numbers do not form a magic square." << endl;
            return 0;
        }
    }//sum of collumns ^^

    int mainDiagonalSum = 0;
    int antiDiagonalSum = 0;
    for (int i = 0; i < N; i++) {
        mainDiagonalSum += grid[i][i];
        antiDiagonalSum += grid[i][N - 1 - i];
    }//diagSums ^^

    if (mainDiagonalSum != magicConstant || antiDiagonalSum != magicConstant) {
        cout << "\nThe numbers do not form a magic square." << endl;
        return 0;
    }
    if (!numcheck) {
        cout << "\nThe numbers form a magic square." << endl;
    }
    else {
        cout << "\nThe numbers DONT form a magic square." << endl;
    }

	return 0;
}
