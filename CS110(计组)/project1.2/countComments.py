AllLineCount=0
CommentLineCount=0
with open("translator.S", encoding='UTF-8') as f:
    Lines=f.readlines()
    for line in Lines:
        AllLineCount+=1
        if line.find("#")>-1:
            CommentLineCount+=1
print(f"Number of code line: {AllLineCount}")
print(f"Number of comments: {CommentLineCount}")
print(f"Comment ratio is {CommentLineCount*100.0/AllLineCount}%")