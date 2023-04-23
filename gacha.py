import random, matplotlib.pyplot as plt
# *3 : 3%, 70位
# *2 : 18.5%, 21位
# *1 : 78.5%, 11位
cardInit = ['藍', '金', '彩']
pool = list(cardInit[0] *785 + cardInit[1] *185 + cardInit[2]*30) #卡池機率
ListX = []
s3List = []
#調整n可以決定10抽幾次
def Gacha(n):
    ctF1 = ctF2 = ctF3 = 0
    
    for x in range(n):
        random.shuffle(pool)
        guaranteeCount = 0 #一次10抽裡面藍色的數量
        ct1 = ct2 = ct3 = 0 #單次10抽的個別數量
        
        #10抽
        for i in range(10):
            #前面9張都藍色的話執行保底
            if guaranteeCount == 9:
                card = '金'
            else:
                gacha = random.randint(0, len(pool)-1)
                card = pool[gacha]
            #出卡
            print(card, end=' ')
            #統計1~3星個別數量
            if card == '彩':
                ct3 += 1
            elif card == '金':
                ct2 += 1
            elif card == '藍':
                guaranteeCount += 1
                ct1 += 1
            #換行    
            if i == 4:
                print()
            elif  ct1 == 9 and ct2 == 1:
                print('\n+19 笑死\n')   
            elif i == 9:
                print('\n')
                
        s3List.append(ct3)        
        #累計每次10抽的個別結果        
        ctF1 += ct1
        ctF2 += ct2
        ctF3 += ct3
        ListX.append(10*(x+1))
        
    print(f'本次模擬結果:\n{n*10}抽，彩色{ctF3}張，金色{ctF2}張，藍色{ctF1}張。')
    plt.title(f"3*:{ctF3}, 2*:{ctF2}, 1*:{ctF1}", fontsize = 20)
Gacha(20)

#折線圖
plt.plot(ListX, s3List, "r--D")
plt.xticks(ListX)
plt.yticks(s3List)
plt.xlabel("Blue Archive", fontsize = 12)
plt.ylabel("3*", fontsize = 12)
plt.ylim(0,10)
plt.show()