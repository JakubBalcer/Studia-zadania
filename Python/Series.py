def get_first_n_len_str(n: int) -> str:
    result = ''
    for x in range(1, 5):
        if space_left(result, n) >= (x * str(x)).__len__():
            result += x * str(x)
        else:
            result += str(x) * space_left(result, n)
    return result


def space_left(word: str, n: int) -> int: return n-word.__len__()


def get_sum(word: str):
    arr = map(lambda x: int(x), list(word))
    return sum(arr)


def main():
    n = int(input('Podaj liczbe n: '))
    word = get_first_n_len_str(n)
    suma = get_sum(word)
    print(f"pierwsze {n} liczb: ", word)
    print("suma: ", suma)


main()
