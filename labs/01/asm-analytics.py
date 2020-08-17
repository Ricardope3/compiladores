import re
from os import system
function = re.compile('0*([\d\w]*) _{1}([^_][\w]+)')
instruction = re.compile('.*\t([\w]*)[\t\n]')

system('make')
system('objdump -d simple_foo > .as')
functions = {}
instructions = {}
with open(".as", "r") as a_file:
    for line in a_file:
        res = function.match(line)
        if res:
            functions[res.group(2)] = res.group(1)
        else:
            res = instruction.match(line)
            if res:
                if(res.group(1) not in instructions):
                    instructions[res.group(1)] = 1
                else:
                    instructions[res.group(1)] += 1
    
print('Hi, this is the output of the analysis:')    
print('\tYou have {} kind of instructions in this object file:'.format(len(instructions)))    

for instr, count in instructions.items():
    print('\t\t{}\t: Executed {} times'.format(instr,count))

print('\t You have {} functions'.format(len(functions)))
for func, addr in functions.items():
    print('\t\t{}\t: Located at {} addr'.format(func,addr))