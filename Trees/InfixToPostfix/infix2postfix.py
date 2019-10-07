# Python 3 program to convert infix to postfix
# This program uses Stack from pythonds 
# A stack can be easily implemented using python list but for maintaining the feel of the algorithm the code here uses Stack()

# pip install pythonds
from pythonds.basic import Stack

# Precedence setting for the operands
def precedence():
    prec = {}
    prec['*'] = 3
    prec['/'] = 3
    prec['+'] = 2
    prec['-'] = 2
    prec['('] = 1
    return prec

def infix2postfix(exp):
    prec = precedence()
    operations = Stack()
    postfixList = []
    tokenList = exp.split()

    for token in tokenList:
        if token in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' or token in '0123456789':
            postfixList.append(token)
        elif token == '(':
            operations.push(token)
        elif token == ')':
            top = operations.pop()
            while top != '(':
                postfixList.append(top)
                top = operations.pop()
        else:
            while not operations.isEmpty() and prec[operations.peek()] >= prec[token]:
                postfixList.append(operations.pop())
            operations.push(token)
    while not operations.isEmpty():
        postfixList.append(operations.pop())
    return ''.join(postfixList)

# Uncomment the following line to test
#print(infix2postfix("A * B + C * D"))
