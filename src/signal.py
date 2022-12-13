import sys


opcode = sys.argv[1]

readF = open("signals.txt", "r")

lines = readF.readlines()

count = len(lines)


print('this->{}.size = {};'.format(opcode, count))

i = 0;
for line in lines:
    print('Signal_array {}_{} = {{'.format(opcode, i), end='')
    first = True
    for c in line.strip():
        if first:
            first = False
            if c == 'X':
                print('0', end='')
            else:
                print(c, end='')
        else:
            if c == 'X':
                print(',0', end='')
            else:
                print(',' + c, end='')
    print('};')
    print('this->{}.control_signals[{}] = {}_{};'.format(opcode, i, opcode, i))
    i = i + 1
