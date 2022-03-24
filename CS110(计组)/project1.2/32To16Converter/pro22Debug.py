Line=[]
with open("out") as f:
    Lines=f.readlines()
    for line in Lines:
        if len(line)<30:
            line=".half 0b"+line
        else:
            line=".word 0b"+line
        Line.append(line)
with open("out",mode="w+") as f:
    f.writelines(Line)