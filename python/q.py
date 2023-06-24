# nums = {1, 2, 3, 4, 5, 6}
# nums = {0, 1, 2, 3} & nums
# nums = filter(lambda x: x > 1, nums)
# print(list(nums))
# print(len(list(nums)))

# def power(x, y):
#   if y == 0:
#     return 1
#   else:
#     return x * power(x, y-1)
# print(power(2, 3))

a = (lambda x: x*(x+1))
print(a)