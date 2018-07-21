###CMPT120 Final Assignment
###Ben,Brian,Nichol

    
import random as r
import math as m

###Matrix(Sample)

def read_string_list_from_file(the_file):
    fileRef = open(the_file,"r")
    localList=[]
    for line in fileRef:
            string = line[0:len(line)-1]
            localList.append(string)
    fileRef.close()
    print ("\n")

    return localList






           

###Player Info
'''
pchoice = input(" Which position shall PythonPlanet be (0..7):")
print ("Data for Player:")
name = input("Name?:")
clevel = input ("Civilization level (0..5):")
ifuel = input("Initial Fuel Litres (0..50):")
maxturns = input("Maximum Turns This Game? (1..10):")
'''     

####Dice

def RollDice():
    adv_num = 0
    adv_num = r.randint(1,6)
    print("You rolled a:",adv_num)
    return adv_num




###Advancing on the Board

def advance_circularly_list (planetList, pos, adv_num): 
	if (pos < 0) or (pos >=len(planetList)):
		Fpos = -1
	else:
		Fpos = (pos + int(adv_num)) % len(planetList)
	print("New position:",Fpos)
	return Fpos



###Explosion(In_Progress)
def gradual_acum(lst,n):
    for i in range(1,Explo):
        acum_list=0
        for k in range(i,Explo):
                acum_list = acum_list + lst[k]

        lst[i] =acum_list
    return lst



def MildExplosion():
    pos_explo=0
    if r.randint(1,len(planetList)*5) <= len(planetList):
        pos_explo= r.randint(1,len(planetList))
        print("OH!, a mild explosion is occuring in planet",pos_explo)
        print ("the board will have more rock specimens!")
        print("Showing board... after mild explosion, still in turn num:",game_turn+1)
 
    else:
        print("No explosions occurred this turn.")
    return pos_explo


###
def create_lists_board(lst,n):
    res=[]
    if (n<4):
        for i in range(1,len(lst)+1):
            if(lst[i-1][n+1].isdigit()):
                res=res+[int((lst[i-1][n])+(lst[i-1][n+1]))]
            else:
                res=res+[int(lst[i-1][n])]
    else:
        for i in range(len(lst)):
            if(lst[i][-2].isdigit()):
                res=res+[int((lst[i][-2])+(lst[i][-1]))]
            else:
                res=res+[int(lst[i][-1])]
    return res


def show_board():
    print("\t","P","\t","C","\t","F","\t","R","\t")
    for i in range(len(planetList)):
        print("\t", planetList[i],"\t",civListT[i],"\t", fuelList[i],"\t", rockList[i],"\t")
        
    return "\n" "P = Planet, C = CivLevel, F = Fuel, R = Rocks"

def cor_binary(lst):
    newlst=[]
    for i in range(len(lst)):
        newlst=newlst+[lst[i]%2]
    print(newlst)
    return newlst

def convert_2_to_10(lst):
    val=0
    for i in range(0,len(lst)):
        
       val+= lst[i]*pow(2,(len(lst)-1-i))
    return val
    

###TOP LEVEL:
    #The lists for the matrix are defined below. Traces provided for reference:

file_name=input("Please present the txt file or d for default:",)
if (file_name=="d"):
    file_name="planetsData1.txt"





### Intro
   
print ("Welcome to the Planet, Alien and Explosions Cmpt 120 Game!")
choice = input("Do you want to play the game? (y/n):",)
choice_check=["y","n"]
while choice not in choice_check:
    choice=input("Invalid input, please type either y or n:",)

  

###Overall game
total_games=0

while (choice=="y"):
    print ("TRACE:",read_string_list_from_file(file_name))
    lst_civ=read_string_list_from_file(file_name)

    civListT= create_lists_board(lst_civ,0) 
    print("TRACE:CIVLIST",civListT)

    fuelList=create_lists_board(lst_civ,2)
    print("TRACE:FUELLIST",fuelList)

    rockList=create_lists_board(lst_civ,4)
    print("TRACE:ROCKLIST",rockList)

    gen_list=[civListT]+[fuelList]+[rockList]
    print("TRACE:LIST OF LIST", gen_list)

    planetList= list(range(len(lst_civ)))

    turns = eval(input("How many turns do you want? (1..10):",))
    turns_check=list(range(1,11))
    while turns not in turns_check:
        turns=eval(input("Please try again, invalid integer (1...10):",))

    p_choice=eval(input("Please select python planet (0...7):",))
    p_choice_check=list(range(8))
    while p_choice not in p_choice_check:
        p_choice=eval(input("Please try again, invalid integer (1...7):",))


    fuel=eval(input("How much fuel do you want to start with (10...50):",))
    fuel_check=list(range(10,51))
    while fuel not in fuel_check:
        fuel=eval(input("Please try again, invalid integer (10...50):",))

    p_civ=eval(input("What is your civilization level (0...3)?:",))
    p_civ_check=list(range(4))
    while  p_civ not in p_civ_check:
        p_civ=eval(input("Please try again, invalid integer (0...3):",))
        
    explosions=input("Do you want to include a mild explosion in this game?(y/n):")
    explosion_check =["y","n"]
    while explosions not in explosion_check:
        explosions=input("Invalid input, please type either y or n:",)
                    
    player_pos=0
    p_rock=[]
    game_turn=0 
    while game_turn<turns and player_pos != p_choice and fuel>0:
        if game_turn+1==1:
            print("Board about to do turn:",game_turn+1)
            print(show_board())
        if explosions =="y":
            print("Showing astronaut ... about to do turn num:",game_turn+1)
            print("Astronaut is on planet:",player_pos)
            print("Fuel count:",fuel)
            Explo = MildExplosion()
            if 1 <= Explo <= len(planetList):
                gradual_acum(rockList,Explo)
            print(show_board())
            Rolldie=input("Do you want to roll a dice (y,n):",)
            Rolldie_check=["y","n"]
            while Rolldie not in Rolldie_check:
                Rolldie=input("Invalid input, please type either y or n:",)
        elif explosions == "n":
            print("Showing astronaut ... about to do turn num:",game_turn+1)
            print("Astronaut is on planet:",player_pos)
            print("Fuel count:",fuel)
            print(show_board())
            Rolldie=input("Do you want to roll a dice (y,n):",)
            Rolldie_check=["y","n"]
            while Rolldie not in Rolldie_check:
                Rolldie=input("Invalid input, please type either y or n:",)
        if Rolldie=="y":
            adv_pos=RollDice()
            player_pos= advance_circularly_list(planetList,player_pos,adv_pos)
        else:
            player_pos=eval(input("Where do you wish to go (0...7):",))
        if(p_civ < civListT[player_pos]):
            fuel_b4=fuel
            fuel=fuel-r.randint(1,fuel)
            print("You lost:",fuel_b4-fuel,"fuel!")
        elif(p_civ==civListT[player_pos]):
            fuel_b4=fuel
            fuel=fuel-r.randint(1,fuel//2)
            print("You lost:",fuel_b4-fuel,"fuel!")
        
        else:
            if(fuelList[player_pos]>0):
                fuel_sub=fuelList[player_pos]-r.randint(1,fuelList[player_pos])
                fuel=fuel+(fuelList[player_pos] - fuel_sub)
                fuelList[player_pos]=fuel_sub
        
        if(rockList[player_pos]>0):
            rock_sub=rockList[player_pos]-(rockList[player_pos]//3)
            p_rock=p_rock+[(rockList[player_pos]-rock_sub)]
            rockList[player_pos]=rock_sub
        print("Your collection of rocks:",p_rock)
        game_turn+=1
        print("-------------------------------------------------------------")
    print("Game Over, Results:")
    if(player_pos==p_choice):
        print(show_board())
        print("Congrats, you've reached PythonPlanet!\n Here are your winning stats:")
        print("Fuel:9999 \nRocks:9999")
        choice=str(input("Do you want to play again (y/n):",))
        choice_check=["y","n"]
        while choice not in choice_check:
            choice=input("Invalid input, please type either y or n:",)
        if choice=="n":
            rem=cor_binary(p_rock)
            print(convert_2_to_10(rem))
    elif game_turn==turns:
        print(show_board())
        print("You ran out of turns before reaching PythonPlanet!\n Here are your end game stats:")
        print("Fuel:",fuel, "\nRocks:", p_rock)
        choice=str(input("Do you want to play again (y/n):",))
        choice_check=["y","n"]
        while choice not in choice_check:
            choice=input("Invalid input, please type either y or n:",)
        if choice=="n":
            rem=(cor_binary(p_rock))
            print(convert_2_to_10(rem))
    elif fuel==0:
        print(show_board())
        print("You ran out of fuel!\nYou are either dead or stranded.\nHere is what you accomplished in life:")
        print("Fuel:", fuel, "\nRocks:", p_rock)
        choice=str(input("Do you want to play again (y/n):",))
        choice_check=["y","n"]
        while choice not in choice_check:
            choice=input("Invalid input, please type either y or n:",)
        if choice=="n":
            rem=(cor_binary(p_rock))
            print(convert_2_to_10(rem))        
    total_games+=1

if (choice=="n"):
    print ("Game Over..........")
        
        






        
