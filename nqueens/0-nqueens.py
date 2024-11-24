#!/usr/bin/python3
'''
Module that solves the N queens problem
'''
import sys


def board_set_up(N):
    """
    Sets up blank NxN chessboard
    """
    matrix = []
    for row in range(N):
        matrix_row = []
        for column in range(N):
            matrix_row.append(0)
        matrix.append(matrix_row)
    return (matrix)


def print_solution(matrix):
    """
    Prints the coordinates where there is a queen
    """
    queens_coordinates = []
    for i, row in enumerate(matrix):
        for j, column in enumerate(row):
            if column == 1:
                queen = []
                queen.append(i)
                queen.append(j)
                queens_coordinates.append(queen)
    print(queens_coordinates)


def is_safe(matrix, new_row, new_column):
    """
    Determines if a queen is safe to be put in new_row, new_column
    """
    for i in range(new_column):
        if matrix[new_row][i]:
            return False
    for i, j in zip(range(new_row, -1, -1),
                    range(new_column, -1, -1)):
        if matrix[i][j]:
            return False
    N = len(matrix)
    for i, j in zip(range(new_row, N, 1),
                    range(new_column, -1, -1)):
        if matrix[i][j]:
            return False
    return True


def solve(matrix, new_column):
    """
    Recursively solves the N Queens puzzle
    """
    N = len(matrix)
    if new_column >= N:
        print_solution(matrix)
        return matrix
    for new_row in range(N):
        if is_safe(matrix, new_row, new_column):
            matrix[new_row][new_column] = 1
            solve(matrix, new_column + 1)
            matrix[new_row][new_column] = 0
    return None


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    N = sys.argv[1]
    try:
        N = int(N)
    except Exception as e:
        print("N must be a number")
        exit(1)
    if N < 4:
        print("N must be at least 4")
        exit(1)
    matrix = board_set_up(N)
    solve(matrix, 0)
