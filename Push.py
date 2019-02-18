import os

AllCnt = 0

README = open('README.md', 'w')

def DirCount(Path):
    Dirs = os.listdir(Path)
    Cnt = 0
    for Dir in Dirs:
        if os.path.isdir(Path + '/' + Dir):
            Cnt += DirCount(Path + '/' + Dir)
        elif os.path.isfile(Path + '/' + Dir):
            Cnt += 1
    return Cnt

def GetREADME():
    global AllCnt
    README.write('# Count of Solved Problems  \n```\n')
    Index = os.getcwd() + '/ACCode'
    OJs = os.listdir(Index)
    OJs.sort()
    for OJ in OJs:
        Cnt = DirCount(Index + '/' + OJ)
        AllCnt += Cnt
        README.write('{:<25s}{:d}{:s}'.format(OJ, Cnt, '  \n'))
    README.write('```\n#### `Total:' + str(AllCnt) + '`\n')

def main():
    GetREADME()
    README.close()
    os.system('git add .')
    os.system('git commit -m Update')
    os.system('git push origin master')

if __name__ == '__main__':
    main()
