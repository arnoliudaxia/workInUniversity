# coding:utf-8
from random import *
import os

# doc: the program automatically generates test cases to test whether your code outputs the correct answer
# usage: put this py in your working directory and just run it
# make sure input.S, main.S and venus-jvm-latest.jar are in the directory
# you can change the arguments below to customize your test cases
minStrLen = 20
maxStrLen = 50
# if you receive the message "WRONG!!", then there is a wrong answer (the case caused the WA is also printed)
# if you receive the message "Run out of steps!", that means you run out of the "steps". You are supposed to simplify your risc-v code.
# (By the way, "steps" means how many operations are executed altogether)
# if the program exit normally, Congratulations!
def LCstring(string1, string2):
    len1 = len(string1)
    len2 = len(string2)
    result = 0
    dp = [[0 for i in range(len1 + 1)] for j in range(len2 + 1)]
    # Attention! You need to implement it by yourself here. It's very very simple if you use dp.
    return result


# print(LCstring("46548916","481"))


# region 生成输入
def randomNumber(digit):
    result = ''
    for i in range(digit):
        result += str(randint(0, 9)) + " "
    return result[:-1]


for testtime in range(20):
    rad1 = randint(minStrLen, maxStrLen)
    rad2 = randint(minStrLen, maxStrLen)
    randomstr1 = str(randomNumber(rad1))
    randomstr2 = str(randomNumber(rad2))
    f = open(r".\input.S", mode="r")
    lines = f.readlines()
    f.close()
    for i in range(len(lines)):
        if lines[i] == "str1:\n":
            lines[i + 1] = "\t.word " + randomstr1 + "\n"
        if lines[i] == "str2:\n":
            lines[i + 1] = "\t.word " + randomstr2 + "\n"
        if lines[i] == "len1:\n":
            lines[i + 1] = "\t.word " + str(rad1) + "\n"
        if lines[i] == "len2:\n":
            lines[i + 1] = "\t.word " + str(rad2) + "\n"
    f = open(r".\input.S", mode="w+")
    f.writelines(lines)

    f.close()
    # endregion
    print()
    rerfer = LCstring(randomstr1.replace(" ", ""), randomstr2.replace(" ", ""))
    print(f"The reference answer: {rerfer}")

    output = os.popen("java -jar venus-jvm-latest.jar main.S").readline()
    print(f"Your answer is: {output}")
    print(randomstr1.replace(" ", ""))
    print(randomstr2.replace(" ", ""))
    if output=="":
        print("Run out of steps!")
    elif rerfer != int(output):
        print("WRONG!!")
        break
