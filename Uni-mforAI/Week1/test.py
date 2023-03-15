from typing import List

def FindLargest(n: int) -> int:
    """_summary_: Tim so lon nhat ma n co the phan hoach duoc, vi du 84 thi se tra ve 4 do 4^3 = 64 < 84 nhung 5^3 = 125 > 84

    Args:
        n (int)

    Returns:
        int: so lon nhat
    """
    largest: int = 0

    for i in range(1, 101):
        if (n < i**3):
            break
        if (n == i**3):
            return 1
        largest = largest + 1

    return largest 

def FindNumPartition(n: int, largest: int) -> int:
    """_summary_: Tim so phan tu trong phan hoach dua vao largest, vi du largest la 4 thi so phan hoac la 7 do 84 = 4^3 + 2^3 + 2^3 + 1^3 + 1^3 + 1^3 + 1^3

    Args:
        n (int)
        largest (int)

    Returns:
        int: so phan tu trong phan hoach
    """
    numOfPartition: int = 0

    while (largest > 1):
        if (n > largest**3):
            n = n - largest**3
            numOfPartition = numOfPartition + 1
        else:
            largest = largest - 1

    if (n > 0):
        return numOfPartition + n

def FindLeastPartition(n: int) -> int:
    """_summary_: Tim cach phan hoach co luong phan tu la it nhat

    Args:
        n (int)

    Returns:
        int: so luong phan tu it nhat ma co the phan hoach duoc
    """
    if (n < 8):
        return n

    largest: int = FindLargest(n)

    if (largest == 1): 
        return largest

    minList: List[int] = []

    while (largest > 0):
        minList.append(FindNumPartition(n, largest))
        largest = largest - 1

    return min(minList)

if __name__ == "__main__":
    assert FindLeastPartition(84) == 6 # True