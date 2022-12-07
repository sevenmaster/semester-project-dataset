types = ['char', 'int', 'double']
with open('template.cpp', 'r') as f:
    data = f.read()

for tA in types:
    for tB in types:
        sc = data.replace('<INCLUES>', '')
                 .replace('TYPE_A', tA))
                 .replace('TYPE_B', tB))
        print(tA, tB)

         
