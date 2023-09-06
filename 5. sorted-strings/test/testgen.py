#! /usr/bin/env python

import string
import random

def random_word(letters, lo=4, hi=15):
    return ''.join(random.choices(letters, k=random.randint(lo, hi)))


def make_test(nwords, letters, lo=4, hi=15):
    words = [random_word(letters, lo, hi) for _ in range(nwords)]
    with open(f'data/in_{nwords}_{lo}_{hi}.txt', 'w') as ofile:
        ofile.write('\n'.join(words))
    with open(f'data/out_{nwords}_{lo}_{hi}.txt', 'w') as ofile:
        ofile.write('\n'.join(sorted(words)))

def main():
    letters = string.digits + string.ascii_letters
    make_test(100, letters)
    make_test(1000, letters)
    make_test(10000, letters)
    make_test(10000, letters, 4, 10)
    make_test(100000, string.ascii_lowercase, 4, 6)
    make_test(500000, string.ascii_lowercase, 4, 6)

if __name__ == '__main__':
    main()
