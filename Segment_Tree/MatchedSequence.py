
class node:
    def __init__(self):
        self.correct = 0
        self.unused_open = 0
        self.unused_close = 0
    


def build(str:str,low:int,high:int,index:int):
    global tree
    if low == high:
        tree[index].correct = 0
        tree[index].unused_open = 1 if str[low] == '(' else 0
        tree[index].unused_close = 1 if str[low] == ')' else 0
        return

    mid = ( low + high ) >> 1
    build(str,low,mid,2*index+1)
    build(str,mid+1,high,2*index+2)

    left = 2*index+1
    right = 2*index+2

    tree[index].correct = min(tree[left].unused_open,tree[right].unused_close) + tree[left].correct + tree[right].correct
    tree[index].unused_open = tree[left].unused_open + tree[right].unused_open - min(tree[left].unused_open,tree[right].unused_close)
    tree[index].unused_close = tree[left].unused_close + tree[right].unused_close - min(tree[left].unused_open,tree[right].unused_close)

def query(low:int,high:int,l:int,r:int,index:int)->node:
    # no overlap
    if l > high or r < low :
        return node()
    
    # complete overlap
    if low >= l and high <= r:
        return tree[index]

    #partial overlap

    mid = ( low + high ) >> 1
    
    left = query(low,mid,l,r,2*index+1)
    right = query(mid+1,high,l,r,2*index+2)


    tree[index].correct = min(left.unused_open,right.unused_close) + left.correct + right.correct
    tree[index].unused_open = left.unused_open + right.unused_open - min(left.unused_open,right.unused_close)
    tree[index].unused_close = left.unused_close + right.unused_close - min(left.unused_open,right.unused_close)

    return tree[index]




def main():
    str= "))))))))((((()))))))(((((((())))))))"
    global tree
    tree = [node() for _ in range(400)]
    n = len(str)
    build(str,0,n-1,0)
    print("Maximum correct pair subsequence length: ",query(0,n-1,0,n-1,0).correct * 2)

if __name__ == '__main__':
    main()