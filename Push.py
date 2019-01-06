import os

AllCnt = 0

README = open('README.md', 'w')

def Work():
    global AllCnt
    README.write('# Count of Solved Problems  \n')
    Index = os.getcwd() + '/AC代码'
    OJs = os.listdir(Index)
    OJs.sort()
    for OJ in OJs:
        Cnt = len(os.listdir(Index + '/' + OJ))
        AllCnt += Cnt
        README.write(OJ)
        README.write('--------------------')
        README.write(str(Cnt))
        README.write('  \n')
    README.write('#### `Total:' + str(AllCnt) + '`\n')

def main():
    Work()
    README.close()
    os.system("git add .")
    os.system("git commit -m Update")
    os.system("git push origin master")

if __name__ == '__main__':
    main()
