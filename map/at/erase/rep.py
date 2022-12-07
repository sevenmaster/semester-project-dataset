import os

sink = """
void __attribute__ ((noinline)) sink(auto val) {
    std::cout << val << std::endl;
}
"""

os.system('sed -i "s/\\[it \\/ 2\\]/ZZZ/g" */*')
data = os.popen('rg -n "\\[(.*)\\] = .*;" -r ".at(\\$1);"')\
        .read().rstrip().split('\n')
for line in data:
    a = line.split(':')
    path, line, text = a[0], a[1], a[2]
    text = '\tsink(' + text.lstrip()
    text = text.replace(';', ');')
    if ".py" in path:
        continue
    with open(path, 'r') as f:
        content = f.read().split('\n')
    content[int(line)-1] = text
    print("-----------------------")
    print(('\n'.join(content)))
    with open(path, 'w') as f:
        f.write('\n'.join(content).replace('// <INCLUDES>', sink))

os.system('sed -i "s/ZZZ/\\[it \\/ 2\\]/g" */*')
