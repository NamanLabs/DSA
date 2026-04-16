# #NOT USED IN COMPANY AS DEPENDENT ON PROCESSOR
# import time
# start = time.time()
# for i in range(1,101) :
#     print(i)
# print(time.time()-start)


# #NOT USED IN COMPANY AS DEPENDENT ON PROCESSOR
# import time
# start = time.time()
# i=1
# while(i<=100):
#     print(i)
#     i+=1
# print(time.time()-start)


def fib(n):
    if n ==1 or n==0 :
        return 1
    else :
        return fib(n-1)+fib(n-2)
print(fib(3))
