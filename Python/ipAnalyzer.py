# IMPORTS
from typing import Tuple

# CLASSES


class NetworkError(Exception):
    def __init__(self):
        super().__init__('Zła maska lub IP')


class Network():
    def __init__(self, ip: str, mask: str):
        self.ip = ip
        self.mask = mask
        self.network_class = None
        self.network_addr = None
        self.broadcast = None

    def get_network_class(self) -> str:
        if self.network_class:
            return self.network_class
        ip = list(map(lambda x: int(x), self.ip.split('.')))
        if ip[0] == 10:
            self.network_class = 'A'
        if ip[0] == 172 and (ip[1] >= 16 and ip[1] <= 31):
            self.network_class = 'B'
        if ip[0] == 192 and ip[1] == 168:
            self.network_class = 'C'
        return self.network_class

    def get_network_addr(self) -> str:
        if self.network_addr:
            return self.network_addr
        ip = list(map(lambda x: (8 - bin(int(x))
                                 [2:].__len__())*'0'+bin(int(x))[2:], self.ip.split('.')))
        mask = list(map(lambda x: (8 - bin(int(x))
                                   [2:].__len__())*'0'+bin(int(x))[2:], self.mask.split('.')))
        output = ''
        for i in range(0, 4):
            for j in range(0, 8):
                if mask[i][j] == '1':
                    output += ip[i][j]
                else:
                    output += '0'
        address = ''
        for i in range(0, 4):
            address += str(int(output[i*8:i*8+8], 2))
            if i != 3:
                address += '.'
        self.network_addr = address
        return self.network_addr

    def get_broadcast(self) -> str:
        if self.broadcast:
            return self.broadcast
        ip = list(map(lambda x: (8 - bin(int(x))
                                 [2:].__len__())*'0'+bin(int(x))[2:], self.ip.split('.')))
        mask = list(map(lambda x: (8 - bin(int(x))
                                   [2:].__len__())*'0'+bin(int(x))[2:], self.mask.split('.')))
        output = ''
        for i in range(0, 4):
            for j in range(0, 8):
                if mask[i][j] == '1':
                    output += ip[i][j]
                else:
                    output += '1'
        address = ''
        for i in range(0, 4):
            address += str(int(output[i*8:i*8+8], 2))
            if i != 3:
                address += '.'
        self.broadcast = address
        return self.broadcast

    @staticmethod
    def validate_mask(mask: str) -> bool:
        try:
            arr = list(map(lambda x: (8 - bin(int(x))
                                      [2:].__len__())*'0'+bin(int(x))[2:], mask.split('.')))

            for i in arr:
                has_zero = False
                for j in i:
                    if j == '0':
                        has_zero = True
                    if j == '1' and has_zero:
                        return False

        except Exception:
            return False
        return True

    @staticmethod
    def validate_ip(ip: str) -> bool:
        arr = list(map(lambda x: int(x), ip.split('.')))
        return all(x <= 255 and x >= 0 for x in arr) and arr.__len__() == 4


# FUNCTIONS

def get_user_input() -> Tuple[str, str]:
    ip = input('Podaj adres ip: ')
    mask = input('Podaj maske podsieci: ')
    if not Network.validate_ip(ip) or not Network.validate_mask(mask):
        raise NetworkError()
    return (ip, mask)

# MAIN FUNCTION


def main() -> None:
    try:
        user_input = get_user_input()
        network = Network(*user_input)
        print('Klasa sieci: '+network.get_network_class())
        print('Adres sieci: '+network.get_network_addr())
        print('Adres broadcast: '+network.get_broadcast())
    except NetworkError as err:
        print(err)


main()
