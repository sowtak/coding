w=input()
ans=[]
for c in w:
    if c in "aiueo":
        continue
    ans.append(c)

print(''.join(ans))
