import random

def generate_seq_list(max):
    numbers = list(range(1, max + 1))
    random.shuffle(numbers)
    print(", splited")
    print(", ".join(map(str, numbers)))
    print("space splited")
    print(" ".join(map(str, numbers)))

def generate_list(n):
    numbers = random.sample(range(-10**6, 10**6), n)
    print(", splited")
    print(", ".join(map(str, numbers)))
    print("space splited")
    print(" ".join(map(str, numbers)))

generate_seq_list(100)
generate_list(100)