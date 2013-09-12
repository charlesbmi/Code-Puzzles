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
        length: length of grid
        grid: a square grid of side-length length, containing an 'm' for bot
            and a 'p' for princess in one of the corners
    '''
    princess_row, princess_col = find_princess(length, grid)
    bot_row, bot_col = find_bot(length, grid)
    row_diff = princess_row - bot_row
    col_diff = princess_col - bot_col
    row_move = 'RIGHT' if row_diff > 0 else 'LEFT'
    col_move = 'DOWN' if col_diff > 0 else 'UP'
    for row in range(abs(row_diff)):
        print(row_move)
    for col in range(abs(col_diff)):
        print(col_move)

def find_princess(length, grid):
    for (row, col) in [(0,0), (length-1,0), (0,length-1), (length-1,length-1)]:
        if grid[row][col] == 'p':
            return row, col

def find_bot(length, grid):
    for row in range(length):
        for col in range(length):
            if grid[row][col] == 'm':
                return row, col

if __name__ == '__main__':
    main()
