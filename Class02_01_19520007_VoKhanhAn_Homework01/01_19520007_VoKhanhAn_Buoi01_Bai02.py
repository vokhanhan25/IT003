# STT 01
# Họ và tên: Võ Khánh An
# Buổi 01 - Bài 02
# Ngôn ngữ: Python 

import random
import math

def init():
    print ('NHAN 1 - CHAY CAU 1')
    print ('NHAN 2 - CHAY CAU 2')
    print ('NHAN 3 - CHAY CAU 3')
    print ('NHAN 4 - CHAY CAU 4')
    print ('NHAN 5 - THOAT KHOI CHUONG TRINH')
    print ('----------------------------------')

def cau1():
    global n
    global a

    for i in range (n):
        print ('a [',i, '] = ', end = ' ')
        a.append(int(input()))

def cau2():
    global n
    global a

    n = random.randint(10, 50)
    for i in range (n):
        a.append(100 + random.randint(100, 120))

def cau3():
    global n
    global a
    print ('n =', n)
    for i in range (0, n):
        print ('a [', i ,'] =', a[i])

def cau4():
    global a
    global n
    a.sort()
    m = 0
    val = []
    cnt = []
    val.append(a[0])
    cnt.append(1)
    for i in range (n-1):
        if a[i] == a[i + 1]:
            cnt[m] = cnt[m] + 1
        else:
            m = m + 1
            val.append(a[i + 1])
            cnt.append(1)
    for i in range (m + 1):
        print ('GIA TRI =', val[i])
        print ('SO LUONG =', cnt[i])
        print ('\n')



a = []

while True:
    init()
    res = int(input())
    if res == 1:
        print ('n = ', end =' ')
        n = int(input())
        cau1()
        print('\n')
    elif res == 2:
        n = 0
        cau2()
        print('\n')
    elif res == 3:
        cau3()
        print('\n')
    elif res == 4:
        cau4()
        print ('\n')
    elif res == 5:
        print ('EXIT')
        exit (0)
    else:
            print ('Ban da nhap sai, vui long nhap lai: ')



