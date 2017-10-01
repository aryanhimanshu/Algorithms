def shellSort(vet):
    n = len(vet)
    gap = int(n/2)
    while gap > 0:

        i = gap
        while i < n:
            temp = vet[i]

            j = i
            while j >= gap and vet[j - gap] > temp:
                vet[j] = vet[j - gap]
                j -= gap

            vet[j] = temp
            i += 1

        gap = int(gap/2)

def test():
    vet = []
    print("Before")
    stri = ''
    for i in range(10, 1, -1):
        vet.append(i)
        stri += str(i) + ' '
    print(stri)

    shellSort(vet)

    print("After")
    stri = ''
    for i in range(0, len(vet)):
        stri += str(vet[i]) + ' '
    print(stri)

test()
