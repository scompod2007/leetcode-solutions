class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        windsum = 0
        n = len(arr)
        cur_mins = []
        ind = 0
        ans = pow(10, 6)
        for i in range(n):
            windsum+=arr[i]
            if windsum == target:
                if i == 0:
                    cur_mins.append(1)
                else:
                    cur_mins.append(min(cur_mins[-1], i-ind+1))
                    if ind > 0 and cur_mins[ind-1] != pow(10, 6):
                        ans = min(ans, i-ind+1+cur_mins[ind-1])
            else:
                if i == 0:
                    cur_mins.append(pow(10, 6))
                    if windsum > target:
                        windsum-=arr[i]
                        ind+=1
                    continue
                if windsum > target:
                    while windsum > target:
                        windsum -= arr[ind]
                        ind+=1
                    if windsum == target:
                        cur_mins.append(min(cur_mins[-1], i-ind+1))
                        if ind > 0 and cur_mins[ind-1] != pow(10, 6):
                            ans = min(ans, i-ind+1+cur_mins[ind-1])
                    else:
                        cur_mins.append(cur_mins[-1])
                else:
                    cur_mins.append(cur_mins[-1])
        if ans > n:
            return -1
        return ans