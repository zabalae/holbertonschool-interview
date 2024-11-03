#!/usr/bin/python3
"""UTF-8 Validation
"""


def validUTF8(data):
    '''
    Method that determines if a given data set represents a valid UTF-8 encoding
    '''
    if not (type(data) is list and all([isinstance(n, int) for n in data])):
        return False

    data = [n + 256 if n < 0 and n > -129 else n for n in data]

    data = [n & 0xFF if n >= 0 else n for n in data]

    try:
        bytes(data).decode(encoding='utf-8', errors='strict')
    except (ValueError, UnicodeDecodeError):
        return False

    return True
