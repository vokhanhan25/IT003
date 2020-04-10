# STT 01
# Họ và tên: Võ Khánh An
# Buổi 02 - Bài 05
# Ngôn ngữ: Python 

import random
import math

def init():
    print ('NHAN 1 - CHAY CAU 1')
    print ('NHAN 2 - CHAY CAU 2')
    print ('NHAN 3 - CHAY CAU 3')
    print ('NHAN 4 - THOAT KHOI CHUONG TRINH')
    print ('----------------------------------')

def cau1():
    global n
    global a
    n = random.randint(10, 50)
    a.append(1)
    a.append(1)
    for i in range (2, n):
        a.append(a[i - 1] + a[i - 2])

def cau2():
    global n
    global a
    print ('n =', n)
    for i in range (n):
        print ('a [', i ,'] =', a[i])

def cau3():
    print ('NHAP PHAN TU O VI TRI THU X MUON XEM TRONG DAY FIBO: ')
    x = int(input())
    print ('PHAN TU O VI TRI THU X CO GIA TRI =', a[x - 1])

a = []
n = 0
while True:
    init()
    res = int(input())
    if res == 1:
        cau1()
        print('\n')
    elif res == 2:
        cau2()
        print('\n')
    elif res == 3:
        cau3()
        print('\n')
    elif res == 4:
        print ('EXIT')
        exit (0)
    else:
            print ('Ban da nhap sai, vui long nhap lai: ')



