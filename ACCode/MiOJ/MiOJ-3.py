def solution(line):
    index = line.find('-')
    a = int(line[:index])
    b = int(line[index + 1:])
    return a - b
