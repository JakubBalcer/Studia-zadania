class CoffeMachine:
    def __init__(self, curr: str = 'zł'):
        self.curr = curr
        self.state = {'1': 0, '2': 0}
        self.acceptedCoins = [1, 2, 5, 0]
        self.running = False
        self.coffee_sold = 0

    def start_machine(self) -> None:
        self.running = True
        print('Uruchomiono maszynę z kawą!')

    def buy_coffee(self, coin: int) -> None:
        if coin not in self.acceptedCoins:
            print('nieprawidłowa moneta ')
            return
        if coin == 0:
            self.running = False
        if coin == 5:
            print('niestety automat nie może sprzedać kawy, nastąpi zwrot pieniędzy')
        if coin == 1:
            self.state['1'] += 1
            self.coffee_sold += 1
            print(
                f'zakupiono 1 kawę, reszta: 0')
        elif coin == 2:
            if self.state['1'] <= 0:
                print('niestety automat nie może sprzedać kawy, nastąpi zwrot pieniędzy')
            else:
                self.state['2'] += 1
                self.coffee_sold += 1
                self.state['1'] -= 1
                print(
                    f'zakupiono 1 kawę, reszta: 1')
        print(
            f'ilość sprzedanych kaw:{self.coffee_sold}, stan kasy: 1{self.curr} : {self.state["1"]}, 2{self.curr} : {self.state["2"]}')

    def prompt_for_action(self) -> None:
        coin = input('prosze wrzucić monete: ')
        try:
            coin = int(coin)
        except ValueError:
            print('Monetę!!!')
            return
        self.buy_coffee(coin)


def main():
    coffe_machine = CoffeMachine()
    coffe_machine.start_machine()
    while coffe_machine.running:
        coffe_machine.prompt_for_action()


main()
