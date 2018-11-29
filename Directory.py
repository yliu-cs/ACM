# -*- coding:utf-8 -*-

import os

AllCnt = 0

README = open('README.md', 'w')

def Change(Str):
    Ans = ""
    for Char in Str:
        InsideCode = ord(Char)
        if InsideCode == 32:
            InsideCode = 12288
        elif InsideCode >= 32 and InsideCode <= 126:
            InsideCode += 65248
        Ans += chr(InsideCode)
    return Ans

def Add(Str, Tar):
    Len = len(Str)
    if Len < Tar:
        for i in range(Tar - Len):
            Str += ' '
    return Str

def Work():
    global AllCnt
    README.write('# Count of Solved Problems  \n')
    Index = os.getcwd() + '/AC代码'
    OJs = os.listdir(Index)
    OJs.sort()
    for OJ in OJs:
        Cnt = len(os.listdir(Index + '/' + OJ))
        AllCnt += Cnt
        README.write(Change(Add(OJ, 16)))
        README.write(Change(str(Cnt)))
        README.write('  \n')
    README.write('###### `Total:' + str(AllCnt) + '`\n')

def main():
    Work()
    README.close()

if __name__ == '__main__':
    main()

