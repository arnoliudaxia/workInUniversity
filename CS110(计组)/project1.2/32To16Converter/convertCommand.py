# coding:utf-8
from random import *
import os
# 这个py将0x格式的十六进制指令全部转化为2进制，注意一行一个

Out=[]
f=open("command.txt")
Lines=f.readlines()
for line in Lines:
    binary=bin(int(line,16))
    binary=str(binary)[2:]
    binary="0" * (32 - len((binary))) + (binary)
    Out.append(binary+"\n")
f.close()

f=open("command.txt",mode="w+")
f.writelines(Out)
f.close()