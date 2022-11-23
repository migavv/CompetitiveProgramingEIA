"""from queue import PriorityQueue

ok = True
aux = 0
while ok:
    players = input()

    if players == None:
        ok = False
    
    else:
        h=0
        q = PriorityQueue()
        while h < int(players):
            playerInfo = input().split(";")
            name = playerInfo[0]
            count = 0

            primerSet = list(playerInfo[1].split())
            segundoSet = list(playerInfo[2].split())
            tercerSet = list(playerInfo[3].split())
            cuartoSet = list(playerInfo[4].split())
            quintaSet = list(playerInfo[5].split())

            for j in range(len(primerSet)):
                if j == len(primerSet)-1 and primerSet[j] == '1':
                    count += 2
                elif primerSet[j] == '1':
                    count += 1
            
            for j in range(len(segundoSet)):
                if j == len(segundoSet)-1 and segundoSet[j] == '1':
                    count += 2
                elif segundoSet[j] == '1':
                    count += 1
            
            for j in range(len(tercerSet)):
                if j == len(tercerSet)-1 and tercerSet[j] == '1':
                    count += 2
                elif tercerSet[j] == '1':
                    count += 1
            
            for j in range(len(cuartoSet)):
                if j == len(cuartoSet)-1 and cuartoSet[j] == '1':
                    count += 2
                elif cuartoSet[j] == '1':
                    count += 1

            for j in range(len(quintaSet)):
                if j == len(quintaSet)-1 and quintaSet[j] == '1':
                    count += 2
                elif quintaSet[j] == '1':
                    count += 1

            q.put((name,count))
        
            h+=1
        
        print("Case " + str(aux+1) + ":")
        while not q.empty():
            jugador = q.get()
            st = ' '.join(map(str, jugador))
            print(st)
            
        aux+=1"""

from queue import PriorityQueue
h=0
ok = True
while ok:

    n = input()

    if n == None:
        ok = False
    
    else:
        q = PriorityQueue()
        for i in range(int(n)):
            count = 0
            playerInfo = input().split(";")

            for j in range(1,len(playerInfo)):
                score=playerInfo[j].split()

                for k in range(len(score)):
                    if(k == len(score)-1 and score[k]=="1"):
                        count += 2
                    elif score[k]=="1":
                        count += 1

            q.put((playerInfo[0],count))

        print("Caso "+str(h+1)+":")

        while not q.empty():
            jugador = q.get()
            print(str(jugador[0]) + " " + str(int(jugador[1])))
        
        h+=1