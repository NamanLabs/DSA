# def sumlist(l):
#     if (l==0):
#         return (1)
#     else:
#         return (l[0] + sumlist(l[1:]))
    



# l=[1,2,3,4]

# print(sumlist(4))






def sumlist(l):
    if len(l) == 0:  # base case: empty list
        return 0
    else:
        return l[0] + sumlist(l[1:])

l = [1, 2, 3, 4]

print(sumlist(l))  # Output: 10