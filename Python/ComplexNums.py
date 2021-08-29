def getNumbersAndType() -> None:
    num1r = float(input())
    num1i = float(input())
    num2r = float(input())
    num2i = float(input())
    t = float(input())
    calculate((num1r, num1i), (num2r, num2i), t)


def calculate(num1: tuple, num2: tuple, t) -> tuple:
    result = ()
    if t == 1:
        result = add(num1, num2)
    elif t == 2:
        result = subtract(num1, num2)
    elif t == 3:
        result = mult(num1, num2)
    elif t == 4:
        result = divide(num1, num2)
    printOutput(result)


def add(num1: tuple, num2: tuple) -> tuple:
    a = complex(*num1)
    b = complex(*num2)
    return a + b


def subtract(num1: tuple, num2: tuple) -> tuple:
    a = complex(*num1)
    b = complex(*num2)
    return a - b


def divide(num1: tuple, num2: tuple) -> tuple:
    a = complex(*num1)
    b = complex(*num2)
    return a / b


def mult(num1: tuple, num2: tuple) -> tuple:
    a = complex(*num1)
    b = complex(*num2)
    return a * b


def printOutput(result: complex) -> None:
    print(result)


getNumbersAndType()
