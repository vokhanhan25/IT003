# STT 01
# Họ và tên: Võ Khánh An
# Buổi 01 - Bài 01
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
    global he
    global mu
    for i in range (n):
        print ('HE SO THU', i + 1, '= ', end = ' ')
        he.append(int(input()))
        print ('MU SO THU', i + 1, '= ', end = ' ')
        mu.append(int(input()))

def cau2():
    global n
    m = random.randint(5, 9)
    while m >= 0:
        he.append(random.randint(10, 100))
        mu.append(m)
        n = n + 1
        m = m - 1

def cau3():
    global n
    print ('y = f(x) =', end = ' ')
    for i in range (0, n - 1):
        print (he[i], 'x^' , mu[i] , '+', end = ' ')
    print (he[n - 1] , 'x^' , mu[n - 1])

def cau4():
    res = 0
    global n
    x = float(input ('x = '))
    for i in range (n):
        res = res + he[i] * math.pow(x, mu[i])
    print ('y = F(x) =' , res)

he = [] 
mu = []

while True:
    init()
    res = int(input())
    if res == 1:
        print ('SO LUONG DON THUC = ', end =' ')
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



