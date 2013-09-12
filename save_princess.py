#!/usr/bin/python
'''
File: save_princess.py
Author: Charles Guan
Last Edit: 2013-09-11
---------------------
Solves the Save Princess intro bot problem at:
https://www.hackerrank.com/challenges/saveprincess

Input:
    First line is an odd integer N < 100, the length of the grid
    Following is an NxN grid where '-' denotes empty cells, 'm' is the bot,
    and 'p' is the princess to save.

Output:
    Print the moves taken to get from the bot to the princess (LEFT, RIGHT, UP,
    or DOWN)
'''

def main():
    '''Entry point for the script'''
    length = int(input())
    grid = [] 
    for i in range(0, length): 
        grid.append(input().strip())
    display_path_to_princess(length, grid)
    
def display_path_to_princess(length, grid):
    '''Prints out the moves taken to get from the bot to the princess
    
    Args:
        length: odd integer, length of grid
        grid: a square grid of side-length length, containing an 'm' for bot
            and a 'p' for princess in one of the corners
    '''
    row_move, col_move = find_princess(length, grid)
    for row in range(int(length / 2)):
        print(row_move)
        print(col_move)

def find_princess(length, grid):
    '''Returns the directions needed to get to the princess'''
    if grid[0][0] == 'p':
        return 'UP', 'LEFT'
    if grid[0][length-1] == 'p':
        return 'UP', 'RIGHT'
    if grid[length-1][0] == 'p':
        return 'DOWN', 'LEFT'
    return 'DOWN', 'RIGHT'

if __name__ == '__main__':
    main()
