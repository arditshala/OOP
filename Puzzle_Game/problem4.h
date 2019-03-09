#ifndef PROBLEM4_H_INCLUDED
#define PROBLEM4_H_INCLUDED

#include <vector>

using namespace std;

typedef vector <int> vec;

class PuzzleBoard
{
    private:
        int** matrix;
        vector<vec> graph;
        int Size;
        pair <int, int> prev;
    public:
        PuzzleBoard(int boardSize, int** matrix = NULL); //create the board
        bool makeMove(int direction); //make a move in the board
        bool getResult();
        friend std::ostream &operator<<(std::ostream &os, PuzzleBoard const &m); //overloading the output operator (print operator)
        int solve(); //solving the puzzle
};

#endif //PROBLEM 4
