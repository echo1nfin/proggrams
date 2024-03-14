from random import shuffle
from time import sleep
from os import system

class blackJack:
    def __init__(self, cards: list = [2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 
                                      5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7,
                                      8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 
                                      10, 10, 10, 10, 10, 10, 10, 10, 10,
                                      10, 10, 10, 10, 'A', 'A', 'A', 'A']) -> None:
        self.cards = cards

    def suffle_cards(self, count: int = 1) -> None:
        for _ in range(count%1001):
            shuffle(self.cards)

    def give_start_cards(self, player, count: int = 2) -> None:
        if len(self.cards) >= count:
            player.hand += [self.cards.pop(0) for _ in range(count)]
        else:
            raise ValueError
        
    def give_more_cards(self, player):
        print(player.hand)
        answer = input("Do you need one more card? (y/n): ")
        while answer == 'y':
            self.give_start_cards(player, 1)
            print(player.hand)
            answer = input("Do you need one more card? (y/n): ")
    def choose_value_A(self, player):
        number_A = 1
        while 'A' in player.hand:
            index_A = player.hand.index('A')
            value = None
            while value != '1' and value != '11':
                print(f"Choose value A {number_A}: ")
                value = input()
            number_A += 1
            player.hand[index_A] = int(value)

    def game_result(self, player1, player2):
        if sum(player1.hand) > sum(player2.hand) and sum(player1.hand) <= 21 or (sum(player2.hand) >= 21 and sum(player1.hand) <= 21):
            print("<<_Player 1 win_>>")
        elif sum(player1.hand) < sum(player2.hand) and sum(player2.hand) <= 21 or (sum(player1.hand) >= 21 and sum(player2.hand) <= 21):
            print("<<_Player 2 win_>>")
        else:
            print("<<_Tie_>>")

    def process_of_shuffle_cards(self):
        print("Карты перемешиваются...")
        for _ in range(3):
            sleep(1)
            print("...")
        sleep(0.5)
        system("cls")
        print("Карты перемешаны")
        sleep(2)
        system("cls")

class Player1(blackJack):
    def __init__(self, hand: list = []) -> None:
        self.hand = hand

class Player2(blackJack):
    def __init__(self, hand: list = []) -> None:
        self.hand = hand

if __name__ == "__main__":
    system("cls")
    Player1 = Player1()
    Player2 = Player2()
    blackJack = blackJack()
    number_shuffles = int(input("Введите сколько раз перемешать карты: "))
    blackJack.suffle_cards(count = number_shuffles)
    system("cls")
    blackJack.process_of_shuffle_cards()
    blackJack.give_start_cards(Player1)
    blackJack.give_start_cards(Player2)
    print("Player 1")
    blackJack.give_more_cards(Player1)
    blackJack.choose_value_A(Player1)
    system("cls")
    print("Player 2")
    blackJack.give_more_cards(Player2)
    blackJack.choose_value_A(Player2)
    system("cls")
    blackJack.game_result(Player1, Player2)
    print(*Player1.hand)
    print(*Player2.hand)
    system("pause")