#3 environment:
#working - not being added 
#staging - get ready to commit but still doesn't. Use "git add (files)" from working / "git rm --cached (files)" back to working status
#commit - git commit -m "(message)"
import random
age = random.randint(1,20)
if age <= 12:
    print("loli")
else:
    print("not loli")
print(age)
def func():
    return