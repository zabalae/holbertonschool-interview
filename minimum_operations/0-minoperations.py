#!/usr/bin/python3
"""
This module defines a function that calculates the minimum number of
operations needed to achieve exactly n H characters.
"""

def minOperations(n):
    """
    Calculates the minimum number of operations needed to reach n H characters.

    Args:
    n (int): The target number of H characters.

    Returns:
    int: The fewest number of operations needed, or 0 if n is impossible.
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
