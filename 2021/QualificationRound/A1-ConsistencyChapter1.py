def to_vowel(letters):
    max_apparitions = letters[0]
    max_index = 0
    for i in range(4, 26):
        if chr(i + ord('A')) in "EIOU" and letters[i] > max_apparitions:
            max_apparitions = letters[i]
            max_index = i
    res = 0
    for i in range(26):
        if i != max_index:
            if chr(i + ord('A')) in "AEIOU":
                res += 2 * letters[i]
            else:
                res += letters[i]
    return res


def to_consonant(letters):
    max_apparitions = letters[1]
    max_index = 1
    for i in range(2, 26):
        if chr(i + ord('A')) not in "EIOU" and letters[i] > max_apparitions:
            max_apparitions = letters[i]
            max_index = i
    res = 0
    for i in range(26):
        if i != max_index:
            if chr(i + ord('A')) in "AEIOU":
                res += letters[i]
            else:
                res += 2 * letters[i]
    return res
