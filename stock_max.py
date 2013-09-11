"""
File: stock_max.py
Author: Charles Guan
Last Edit: 2013-09-10
---------------------
Solves the problem listed at https://www.hackerrank.com/challenges/stockmax
Given certain stock prices for the next N days, computes the max profit from an
optimal trading strategy.

Input:
    First line contains number of test cases T. T test cases follow:
    Each test case consists of two lines. The first contains a number N.
    The second contains N space-separated integers with the stock price.

Output:
    T lines, each containing the max profit for the matching test case
"""

def main():
    '''The entrance point for the application.'''
    num_cases = int(input())
    for i in range(num_cases):
        num_prices = int(input())
        prices = list(map(int, input().split()))
        print(max_profit(prices, num_prices))
    
def max_profit(prices, num_prices):
    '''Returns the max profit

    Computes and returns the max profit possible from trading stocks given
    by the prices list.

    Args:
        prices: list of integers corresponding to stock price for each day
        num_prices: length of prices list

    Returns:
        profit: computed profit attainable from optimal trading strategy.
    '''
    stocks_owned = 0
    profit = 0
    for i, price in enumerate(prices):
        if (i == num_prices - 1) or (price > max(prices[i+1:])):
            # Sell all stocks
            profit += price * stocks_owned
            stocks_owned = 0
        else:
            # Buy a stock
            profit -= price
            stocks_owned += 1
    return profit

if __name__ == '__main__':
    main()
