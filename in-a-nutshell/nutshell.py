# it is a commentary


import random                      # random.randint()
import random as ran               # ran.randint()
from random import randint         # randint()
from random import randint as rani # rani()


simple_global_variable = "value"


# all identifier below, except `_none`, less '_' are
# the name of the type convertion functions
_str = "string"
_int = 0
_float = 0.0
_tuple = () # constant values
_list = []
_dict = {} # `"foo": 0`
_bool = False
_none = None


# foo_list
fl = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

fl_chunks = [ # it works in string, tuples and lists
    fl[:],     # [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    fl.copy(), # [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    fl[0:2],   # [9, 8]
    fl[1::2],  # [8, 6, 4, 2, 0]
    fl[2:6:3], # [7, 4]
] # [ <first-index> : <last-index> : <step-length> ]


FOO_TUPLE   = ("a", "b", "c")
OTHER_TUPLE = FOO_TUPLE
FOO_DICT    = {"a": 0, "b": 1, "c": 2}

if "a" in FOO_TUPLE: # True
    print("It has the value!")

elif FOO_TUPLE is OTHER_TUPLE: # True
    print("Like the JS operator: '==='")

elif "b" in FOO_DICT: # True
    print("This is a FOO message!!")

elif 2 in FOO_DICT: # False
    print("It has a number key!!!")

else:
    raise Exception("It is an exception!")

# <value-if-true> if <condition> else <value-if-false>
ternary_result = 1 if True else 0
ternary_result = ("a" if True else "A") if True else "b"
ternary_result = "a" if False else ("b" if True else "B")


TO_FOR_LOOPS = (9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
TO_FOR_LOOPS_2 = {"a": 9, "b": 8, "c": 7}

for i in range( len(TO_FOR_LOOPS) ):
    print(TO_FOR_LOOPS[i])

for cur in TO_FOR_LOOPS:
    print(cur)

for i, v in enumerate(TO_FOR_LOOPS):
    print(v) # or: print(TO_FOR_LOOPS[i])

for k, v in TO_FOR_LOOPS_2.items():
    print(k + ": " + str(v)) # or: print(k + ": " + TO_FOR_LOOPS_2[k])


while False: # False
    pass # it allow declare an empty block

while False and True: # False
    pass

while False or False: # False
    pass

while not True: # False
    pass


def count(_max):
    for i in range(_max):
        yield i

for n in count(5):
    print(n)


# indentation instead of the traditional "{}"
generic = "FOO"

def i_am_a_function(arg):
    if arg:
        global generic # get from global scope
        print(generic) # "FOO"

def other_function(arg):
    generic = None

    def child():
        nonlocal generic # get from the scope above
        generic = "BAR"

    child()
    return generic # "BAR"


# decorators are called every that a linked function
# is called; the linked function will be called only
# if it decorator(s) call it, otherwise only the
# decorator(s) will be called

def simple_decorator(func):
    func("Hello world!")

@simple_decorator # it always will be called before `any_function`
def any_function(msg):
    return msg # print and return `msg`

def complex_decorator(*args):
    def core(func):
        full_msg = ""
        MAX = len(args)

        for i, v in enumerate(args):
            full_msg += v
            if i != MAX - 1:
                full_msg += " "

        print(full_msg)
        return func(19, 60)

    return core

@complex_decorator("Hello", "world")
def other_any_function(n0, n1):
    return n0 + n1

# print: 0\nboss\n1\nBOSS
def second_decorator(func):
    print("1")
    func("BOSS")

def first_decorator(func):
    print("0")
    func("boss")
    return func # return `boss_function` for the `second_decorator`

@second_decorator
@first_decorator
def boss_function(msg):
    print(msg)


class Foo:
    # `self` allow that the function can
    # to access the object, less it
    def __init__(self, num): # constructor
        self.num = num
        pass

    def __del__(self): # destructor
        pass

    def no_self():
        pass

    def to_override():
        pass

    @staticmethod
    def static_method():
        pass

class Bar(Foo): # inherit from `Foo`
    property = 0

    def __init__(self, num):
        super().__init__(num)

    def to_override():
        print("It was overrided")

Foo.static_method()
foobar = Foo(5)
del foobar # call the Foo desctrutor


def receive_a_function(lamb):
    try:
        lamb("Hello world!")

    except Exception as ex: # `as` is optional, but necessary to access the exception
        print("An 'Exception' was catched")

    except: # any type
        print("An error occur!")

    else: # it will be called if none exception thrown
        print("Sucess!!")

    finally: # it is always called (avoid it)
        print("The try-except ended")

receive_a_function(lambda msg: print(msg))


try:
    with open("foo.bar", "r") as file:
        pass
except:
    print("'foo.bar' do not exist")


from asyncio import sleep as slp, run # as r

async def sleep():
    await slp(5) # wait 5 seconds

run( sleep() )
