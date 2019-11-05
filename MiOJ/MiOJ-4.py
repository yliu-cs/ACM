def solution(line):
    data = list(map(int, line.split(',')))
    data.sort()
    ans = 1
    cnt = 1
    for i in range(len(data)):
        if i == 0:
            continue
        if data[i] == data[i - 1] + 1:
            cnt += 1
            ans = max(ans, cnt)
        else:
            cnt = 1
    return ans
