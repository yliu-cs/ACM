import os

all_cnt = 0

README = open('README.md', 'w')

def CntFile(idx):
    dirs = os.listdir(idx)
    cnt = 0
    for dir in dirs:
        path = idx + '/' + dir
        if os.path.isdir(path):
            cnt += CntFile(path)
        elif os.path.isfile(path):
            cnt += 1
    return cnt

def GetREADME():
    global all_cnt
    README.write('# Count of Solved Problems  \n```\n')
    idx = os.getcwd()
    ojs = os.listdir(idx)
    for oj in ojs:
        path = idx + '/' + oj
        if os.path.isdir(path) and oj != '.git':
            cnt = CntFile(path)
            all_cnt += cnt
            README.write('{:<25s}{:d}{:s}'.format(oj, cnt, '  \n'))
    README.write('```\n#### `Total:' + str(all_cnt) + '`\n')

def main():
    GetREADME()
    README.close()
    os.system('git add .')
    os.system('git commit -m update')
    os.system('git push origin master')

if __name__ == '__main__':
    main()