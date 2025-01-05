#!/usr/bin/python3
"""
-Prototype: def rain(walls)
-walls is a list of non-negative integers.
-Return: Integer indicating total amount of rainwater retained.
-Assume that the ends of the list (before index 0 and after index walls[-1])
-are not walls, meaning they will not retain water.
-If the list is empty return 0.
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains
    """
    if not walls:
        return 0

    n = len(walls)
    left = [0] * n
    right = [0] * n

    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    right[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    water = 0
    for i in range(n):
        water += min(left[i], right[i]) - walls[i]

    return water
