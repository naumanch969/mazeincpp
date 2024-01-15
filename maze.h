#pragma once

#include "fundamentals.h"

int find(vector<int>& parent, int i)
{
    if (parent[i] == i)
    {
        return i;
    }
    return find(parent, parent[i]);
}
void Union(vector<int>& parent, vector<int>& rank, int x, int y)
{
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);

    if (rank[xRoot] < rank[yRoot])
    {
        parent[xRoot] = yRoot;
    }
    else if (rank[xRoot] > rank[yRoot])
    {
        parent[yRoot] = xRoot;
    }
    else
    {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}
vector<vector<char>> generateMaze(int rows, int cols)
{
    vector<Wall> walls;
    int r = rows * 2 + 1;
    vector<char> v(mazeCols * 2 + 1, 219); // 219 is ASCII value of solid box (of maze wall)
    vector<vector<char>> maze(r, v);       // rows, cols

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (i > 0)
            {
                walls.push_back({ {i, j}, {i - 1, j} }); // Vertical walls
            }
            if (j > 0)
            {
                walls.push_back({ {i, j}, {i, j - 1} }); // Horizontal walls
            }
        }
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(walls.begin(), walls.end(), g);

    vector<int> parent(rows * cols);
    vector<int> rank(rows * cols, 0);

    for (int i = 0; i < rows * cols; ++i)
    {
        parent[i] = i;
    }

    for (const auto& wall : walls)
    {
        auto cell1 = wall.cell1;
        auto cell2 = wall.cell2;

        int root1 = find(parent, cell1.first * cols + cell1.second);
        int root2 = find(parent, cell2.first * cols + cell2.second);

        if (root1 != root2)
        {
            maze[2 * cell1.first + 1][2 * cell1.second + 1] = ' ';
            maze[2 * cell2.first + 1][2 * cell2.second + 1] = ' ';
            maze[cell1.first + cell2.first + 1][cell1.second + cell2.second + 1] = ' ';
            Union(parent, rank, root1, root2);
        }
    }

    // Entrance and exit points
    maze[1][0] = 'S';                   // Start
    maze[rows * 2 - 1][cols * 2] = 'E'; // End

    return maze;
}
