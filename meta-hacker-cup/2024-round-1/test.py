ans = [1]

for i in range(1, 11):
    x = 0.5
    a = 1
    b = 2
    for j in range(100):
        a += 1 + ans[i-1]
        b *= 2
        x += a/b

    ans.append(round(x))

print(ans)