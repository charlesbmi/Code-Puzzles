'''
File: frequent_terms.py
Author: Charles Guan
Last Edit: 2012-09-15
---------------------
This module counts the most frequent terms in an input text file.

Input:
    First line is the number of terms in the input.
    Next N lines each contain a term.
    Last line is k, the number of most frequent terms to print.

Output:
    The k most frequent terms in descending order of frequency. Two terms with
    the same frequency are printed in lexocographical order.
'''

import collections
from operator import itemgetter

def main():
    # Read terms into dictionary
    num_input_terms = int(raw_input())
    term_counter = {}
    for i in xrange(num_input_terms):
        term = raw_input()
        term_counter[term] = term_counter.get(term, default=0) + 1
    num_output_terms = int(raw_input())
    # Sort terms by secondary (lexocographic) order first,
    # then by primary (count) order
    # term_counter.items() has format [(key, value), ...]
    terms_lex_order = sorted(term_counter.items(), key=itemgetter(0))
    terms_count_order = sorted(terms_lex_order, key=itemgetter(1), reverse=True)
    for rank in xrange(num_out_terms):
        print(terms_count_order[rank][0])

if __name__ == '__main__':
    main()

