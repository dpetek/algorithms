'''
Created on Apr 27, 2012

@author: dpetek
'''
n,m = 0,0
words=[]
dp = []
MOD = 1000000007

def appendStrToNum(num, s):
    for c in s:
        num*=10
        num+=ord(c) - ord('a') + 1
    return num

if __name__ == '__main__':
    [n, m] = [int(x) for x in raw_input().split(' ')]
    for i in range(0, n):
        words.append(raw_input())
    for i in range(0, m+1):
        dp.append(dict())
    dp[0][0] = 1
    for i in range(0,n):
        print "%d/%d" % (i, n)
        for j in range(len(words[i]), m+1):
            d = dp[j - len(words[i])] 
            for key,value in d.iteritems():
                num = appendStrToNum(key, words[i])
                if not num in dp[j]: 
                    dp[j][num] = 0
                dp[j][num] += dp[j - len(words[i])][key]
                dp[j][num] %= MOD
    cnt = 0
    for i in range(0, m+1):
        for key in dp[i]:
            print "%d %d => %d" % (i, key, dp[i][key])
            cnt+=dp[i][key]
            cnt%=MOD
    print cnt         
    