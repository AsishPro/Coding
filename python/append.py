if __name__ == '__main__':
    record=[]
    for _ in range(int(input())):
        name = input()
        score = float(input())
        record.append([score,name])
    record=set(record.sort())
    print(record)
    