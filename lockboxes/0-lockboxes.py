#!/usr/bin/python3
def canUnlockAll(boxes):
    '''
    Determines if all the boxes can be unlocked.

    A box can be unlocked if you have a key that corresponds to its index.
    The first box (index 0) is always unlocked. You can use keys found in
    unlocked boxes to unlock other boxes. Each box contains a list of keys
    to other boxes.

    Args:
        boxes (list of lists): A list of boxes, where each box is represented
                               as a list of keys. The index of each sublist
                               represents a box, and the elements of the sublist
                               are the keys to other boxes.

    Returns:
        bool: True if all boxes can be unlocked, False otherwise.
    '''
    n = len(boxes)
    unlocked = [False] * n
    unlocked[0] = True
    keys = [0]

    while keys:
        current_box = keys.pop()
        for key in boxes[current_box]:
            if key < n and not unlocked[key]:
                unlocked[key] = True
                keys.append(key)

    return all(unlocked)
