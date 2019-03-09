#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "problem4.h"
#define INF INT_MAX

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int posX[4]={-1,0,1,0};
int posY[4]={0,1,0,-1};

std::ostream &operator<<(std::ostream &os, PuzzleBoard const &m)
{
    for (int i=0; i<m.Size; i++)
    {
        for (int j=0; j<m.Size; j++)
        {
            cout << m.matrix[i][j] << "  ";
        }
        cout << endl;
    }
    return os;
};

bool PuzzleBoard::makeMove(int direction)
{
    int len = matrix[prev.first][prev.second];
    bool helper = false;

    switch(direction)
    {
        case 0 : if (prev.first - len >= 0) {prev.first = prev.first - len; helper = true;}; break;

        case 1 : if (prev.second + len < Size) {prev.second = prev.second + len; helper = true;}; break;

        case 2 : if (prev.first + len < Size) {prev.first = prev.first + len; helper = true;}; break;

        case 3 : if (prev.second - len >= 0) {prev.second = prev.second - len; helper = true;}; break;

        default : cout << "Invalid Move";
    }

    return helper;
}

bool PuzzleBoard::getResult()
{
    if (prev.first == Size - 1 && prev.second == Size -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int PuzzleBoard::solve()
{
    prev = make_pair(0, 0);

    vector<int> rowIni(Size, INF);
    vector<vector<int> > dist(Size, rowIni);
    dist[0][0] = 0;

    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0,0));

    while (!pq.empty())
    {
        ii u = pq.top();
        pq.pop();

        for (int j = 0; j < 4; j++) {

            int newX =u.first + posX[j]*graph.at(u.first)[u.second];
            int newY =u.second + posY[j]*graph.at(u.first)[u.second];
            if((newX >= 0 && newX < Size) && (newY >= 0 && newY < Size)){
                if (dist.at(u.first)[u.second] + 1 < dist.at(newX)[newY]) {
                    dist.at(newX)[newY] = dist.at(u.first)[u.second]  + 1;
                    ii newV (newX,newY);
                    pq.push(newV);
                }
            }
        }
    }

    if (dist[Size-1][Size-1] == INF)
    {
        return -1;
    }
    else
    {
        return dist[Size-1][Size-1];
    }
}

PuzzleBoard::PuzzleBoard(int Size, int** matrix)
{
    this->Size = Size;


    if (matrix == NULL)
    {
        this->matrix = new int*[Size];
        for (int i = 0; i < Size; i++)
            this->matrix[i] = new int[Size];
        srand (time(NULL));
        int randValue;

        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                randValue = rand() % (Size - 1) + 1;
                this->matrix[i][j] = randValue;
            }
        }

        for(int row = 0; row < Size; row ++)
        {
            vector<int> rowdata;
            for(int col = 0; col < Size; col++)
            {
                rowdata.push_back(this->matrix[row][col]);
            }
            graph.push_back(rowdata);
        }
    }

    else
    {
        this->matrix = matrix;

        for(int row = 0; row < Size; row ++)
        {
            vector<int> rowdata;
            for(int col = 0; col < Size; col++)
            {
                rowdata.push_back(matrix[row][col]);
            }
            graph.push_back(rowdata);
        }
    }

    prev = make_pair(0, 0);
}
