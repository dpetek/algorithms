'''
Created on Apr 24, 2012

@author: dpetek
'''

fact=[]
for i in range(0,55):
    fact.append(1 if i <= 1 else i * fact[i-1])

nums = []
n = 0
smaller = []
bigger  = []

dp = [[[0 for i in range(0, 55)] for j in range(0, 55)] for k in range(0,55)]

def preprocess():
    global smaller
    global bigger
    global n
    global nums
    global fact 
    for i in range(0, n):
        smaller.append(0)
        bigger.append(0)
        for j in range(0, n):
            if i == j : continue
            if nums[j] >= nums[i]:
                bigger[i] = bigger[i] + 1
            else:
                smaller[i] = smaller[i] + 1


def calcCombinations(pos, dist, s, b):
    global smaller
    global bigger
    global n
    global nums
    global fact 
    if dist > pos: return 0
    if pos == 1:
        if dist == 1: return fact[s + b]
        else: return 0
    ret = 1
    #print ">>bs %d %d" %(b,s)
    if pos!=dist:
        ret = b
        b = b - 1
    #print ">Chosing one to break: %d" % ret
    _s = s
    for i in range(1, dist):
        ret = ret * _s
        #print ">Choosing smaller in the middle %d" % _s
        _s = _s - 1
        if _s < 0: break
    if _s + b > 0:
        ret = ret * fact[_s + b]
    #print ">Left: %d" % (_s + b)
    return ret
    
def calc():
    global smaller, bigger, n, nums, fact
    ret_sum = 0.0
    for i in range(0, n):
        stick_sum = 0
        for pos in range(1, n+1):
            for sz in range(1, n+1 ):
                dp[i][pos][sz] = calcCombinations(pos, sz, smaller[i], bigger[i])
                stick_sum += sz * dp[i][pos][sz]
                #if dp[i][pos][sz] != 0 : print "dp[%d][%d][%d]=%d" %(i, pos, sz, dp[i][pos][sz])
        ret_sum += 1.0 * stick_sum / fact[n]
    return ret_sum

if __name__ == '__main__':
    t = int(raw_input())
    for tt in range(0,t):
        nums = []
        n = 0
        smaller = []
        bigger  = []
        
        dp = [[[0 for i in range(0, 55)] for j in range(0, 55)] for k in range(0,55)]

        n = int(raw_input())
        nums = [int(x) for x in raw_input().split(" ")]
        nums.sort()
        preprocess()
        print "%.2f" % calc()