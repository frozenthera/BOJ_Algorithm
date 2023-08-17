N = int(input())

ans = [[1,1], [1,0]]
cache = {}

def powMat(mat, n):
    if n == 1:
        return mat
    
    if n in cache:
        return cache[n]
    
    if n % 2 == 0:
        cache[n] = mulMat(powMat(mat, n//2), powMat(mat, n//2)) 
        return cache[n]
    else:
        cache[n] = mulMat(mulMat(powMat(mat, (n-1)//2), powMat(mat, (n-1)//2)), mat)
        return cache[n]

def mulMat(mat1, mat2):
    return [[(mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0]) % 1000000007, (mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1]) % 1000000007],
            [(mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0]) % 1000000007, (mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1]) % 1000000007]]

print(powMat(ans, N)[0][1] % 1000000007)