# STT 01
# Họ và tên: Võ Khánh An
# Buổi 02 - Bài 03
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
    a = []
    n = random.randint(15, 30)
    n = 50
    for i in range (n):
        a.append(random.randint(555, 999))

def cau2():
    global n
    global a
    a = []

    n = 1
    a.append (random.randint(10,99))
    while a[n - 1] < 99:
        a.append(random.randint(a[n - 1] + 1, 99))
        n = n + 1

def cau3():
    global n
    global a
    print ('n =', n)
    for i in range (n):
        print ('a [', i ,'] =', a[i])

def bs(x):
    global a
    l = 0
    r = n -1
    while l <= r:
        m = int(l + ((r-l) / 2))
        if x == a[m]:
            return m
        if x < a[m]:
            r = m - 1
        else:
            l = m + 1
    return -1


def cau4():
    global a
    global n
    a.sort()
    print ('NHAP X = ', end = ' ')
    x = int(input())
    if bs(x) != -1:
        print ('PHAN TU X XUAT HIEN TRONG DANH SACH')
    else:
        print ('PHAN TU X KHONG XUAT HIEN TRONG DANH SACH')

a = []

while True:
    init()
    res = int(input())
    if res == 1:
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



