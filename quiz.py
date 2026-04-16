
nums = [1, 2, 3]
vals = nums
del vals[:]

x = 1
y = 2
x, y, z = x, x, y
z, y, z = x, y, z

print(x, y, z)

