import os

AllCnt = 0

README = open('README.md', 'w')

def Work():
    global AllCnt
    README.write('# Count of Solved Problems  \n```\n')
    Index = os.getcwd() + '/ACCode'
    OJs = os.listdir(Index)
    OJs.sort()
    for OJ in OJs:
        Cnt = len(os.listdir(Index + '/' + OJ))
        AllCnt += Cnt
        README.write('{:<25s}{:d}{:s}'.format(OJ, Cnt, '  \n'))
    README.write('```\n#### `Total:' + str(AllCnt) + '`\n')

def main():
    Work()
    README.close()
    os.system("git add .")
    os.system("git commit -m Update")
    os.system("git push origin master")

if __name__ == '__main__':
    main()
