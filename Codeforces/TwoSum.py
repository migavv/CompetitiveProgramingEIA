def twoSum(nums, target):

    hashmap = {}
    result = []

    for i in range(len(nums)-1):
        hashmap[nums[i] + nums[i+1]] = i,i+1

    if target in hashmap:
        result = list(hashmap[target])

    return result

print(twoSum([2,7,11,15],9))
