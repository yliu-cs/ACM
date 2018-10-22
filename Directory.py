# -*- coding:utf-8 -*-

import os

README = open('README.md', 'w')

AllCnt = 0;

def AC_Code():
    global AllCnt
    README.write('%s\n' % '## AC Code:')
    OJPos = os.getcwd() + '/AC代码'
    OJs = os.listdir(OJPos)
    for OJ in OJs:
        Cnt = 0
        ProblemPos = OJPos + '/' + OJ
        Problems = os.listdir(ProblemPos)
        ProblemList = []
        for Problem in Problems:
            ProblemList.append(Problem)
            Cnt += 1
            AllCnt += 1
        ProblemList.sort()
        README.write('%s\n' % str('### ' + OJ))
        for Problem in ProblemList:
            README.write('%s\n' % str('* [' + Problem[:-4] + '](https://github.com/Tony5t4rk/ACM/tree/master/AC代码/' + OJ + '/' + Problem + ')'))

def main():
    AC_Code()
    README.write('\n%s\n' % '![](http://p980l5uv6.bkt.clouddn.com/18s.jpg)')
    README.close()
    print('Cnt=', AllCnt)

if __name__ == '__main__':
    main()

