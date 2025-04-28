#msg("starting program")

from datetime import datetime
from random   import randint
import time

def msg(m) -> None:
    time.sleep(randint(1, 10))
    print(f"{m.title()}...\n")

def endl():
    print("\n", end="")


msg("declaring constants")

PI = 3.14
ASCII_START_CODE = 97
TIME_NOW = datetime.today().strftime('%Y-%m-%d')
RANDOM_PASSWORD = randint(0, 100)
TRUE_PASSWORD = True


msg("wainting use informations")

USER_MSG = (
    "Please report your name:",
    "An error occur, please try again:",
    "Sorry, other error. Report again:",
)

user = ""
for i in range(0, 3):
    user = input( USER_MSG[i] + " " )

    time.sleep(randint(2, 6))

user = "Potato user"
endl()

msg("wait")
time.sleep(12)

PASS_MSG = (
    "Please report the RANDOM password:",
    "Try again:",
    "Suspicious... try again:",
    "(Bro???) again:",
    "OK, last change:",
)

password = None
for i in range(0, 5):
    password = input(PASS_MSG[i] + " ")

    if password == RANDOM_PASSWORD:
        print("It was not hard, right?")
        break
    else:
        password = None

    time.sleep(randint(4, 10))

time.sleep(2)
endl()

if password == None:
    print("You won't receive the BIG reward! Impostor!!")
else:
    print(f"Enjoy your reward: {REWARD}")

endl()
msg("finishing")

print(f"""
=================================== {TIME_NOW}
User name: {user}
Random password: {TRUE_PASSWORD}
User age: {False}
Work time: -1h
PI value: {PI}
ASCII random chararacter: {ASCII_START_CODE}
----------------------------------- {TIME_NOW}
> > > Hello world! < < <
=================================== {None}
""")
