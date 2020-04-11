# STT 01
# Họ và tên: Võ Khánh An
# Buổi 02 - Bài 04
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
    a = []

    n = random.randint(5, 10)
    for i in range (n):
        a.append(random.randint(-10, 10))

def cau2():
    global n
    global a
    print ('n =', n)
    for i in range (n):
        print ('a [', i ,'] =', a[i])

def cau3():
    global n
    global a
    
    cnt0 = 0
    cntNeg = 0
    product = 1
    maxNeg = -1000000000
    for i in range(n):
        if a[i] == 0: 
            cnt0 = cnt0 + 1
        else:
            if a[i] < 0:
                cntNeg = cntNeg + 1
                maxNeg = max(maxNeg, a[i])
            product = product * a[i]
    
    if (cnt0 == n or (cntNeg == 1 and cnt0 == n - 1)):
        return 0
    if (cntNeg % 2 == 1):
        product = int (product / maxNeg)
    return product

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
        print ('TICH LON NHAT CUA CAC TAP CON = ', cau3())
        print('\n')
    elif res == 4:
        print ('EXIT')
        exit (0)
    else:
            print ('Ban da nhap sai, vui long nhap lai: ')



