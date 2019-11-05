def solution(line):
    ans = 0
    data = list(map(int, line.split(',')))
    for i in range(len(data)):
        for j in range(i):
            if data[j] > data[i]:
                ans += 1
    return ans
