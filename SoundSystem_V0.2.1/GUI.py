import math
import time
import re


from math import cos, sin

import serial # pip install pyserial
import pygame # pip install pygame

pygame.init()

WIDTH = 1000
HEIGHT = 620
icon = pygame.image.load('assets/icon.png') 
pygame.display.set_icon(icon)
sol = pygame.image.load("assets/clef_sol.png")
fa = pygame.image.load("assets/clef_fa.png")
screen = pygame.display.set_mode([WIDTH, HEIGHT])
pygame.display.set_caption('MySynth') 

arduinoData = serial.Serial('com3', 9600)
timer = pygame.time.Clock()
fps = 60
w, h = 3, 7
font = pygame.font.Font('freesansbold.ttf', 24)

def parse_data(fulldata):
    x = 0
    lenght = len(fulldata) - 5
    Data = ["","","","","","","",""]
    temp = ''
    for i in range(2 , lenght):
    
        if fulldata[i] != '-' and fulldata[i] != '/':
            temp = temp + fulldata[i]

        elif fulldata[i] == '/' or fulldata[i] == '-':
            i += 1
            Data[x] = temp

            if x<7:x += 1
            temp = ''
        else:
            pass

    return(Data)

def draw_screen(data):
    # title
    screen.blit(font.render(f'SYNTHETISER', True, 'red'), (67, 10))
    screen.blit(font.render(f'NOTES', True, 'red'), (630, 10))

    # first staff
    pygame.draw.rect(screen, 'white', (320, 75, 650, 2))
    pygame.draw.rect(screen, 'white', (320, 125, 650, 2))
    pygame.draw.rect(screen, 'white', (320, 175,650, 2))
    pygame.draw.rect(screen, 'white', (320, 225, 650, 2))
    pygame.draw.rect(screen, 'white', (320, 275, 650, 2))
    screen.blit(sol, (220, 0))

    # bass staff
    pygame.draw.rect(screen, 'white', (320, 375, 650, 2))
    pygame.draw.rect(screen, 'white', (320, 425, 650, 2))
    pygame.draw.rect(screen, 'white', (320, 475, 650, 2))
    pygame.draw.rect(screen, 'white', (320, 525, 650, 2))
    pygame.draw.rect(screen, 'white', (320, 575, 650, 2))

    screen.blit(fa, (325, 375))

    # note
    note1 = re.sub('\r','\n',data[1]).strip()
    note2 = re.sub('\r','\n',data[3]).strip()
    note3 = re.sub('\r','\n',data[5]).strip()
    note4 = re.sub('\r','\n',data[7]).strip()
    pygame.draw.circle(screen, 'white', (575, (60000 / float(note1)) if note1 > 0 else 0), 20)
    pygame.draw.circle(screen, 'white', (675, (60000 / float(note2)) if note2 > 0 else 0), 20)
    pygame.draw.circle(screen, 'white', (775, (60000 / float(note3)) if note3 > 0 else 0), 20)
    pygame.draw.circle(screen, 'white', (875, (60000 / float(note4)) if note4 > 0 else 0), 20)

    pygame.draw.circle(screen, 'dark gray', (75 + 150, 160), 60)
    screen.blit(font.render(f'{data[1]}', True, 'black'), (55 + 150, 150))
    pygame.draw.circle(screen, 'dark gray', (75 + 150, 290), 60)
    screen.blit(font.render(f'{data[3]}', True, 'black'), (55 + 150, 280))
    pygame.draw.circle(screen, 'dark gray', (75 + 150, 420), 60)
    screen.blit(font.render(f'{data[5]}', True, 'black'), (55 + 150, 410))
    pygame.draw.circle(screen, 'dark gray', (75 + 150, 550), 60)
    screen.blit(font.render(f'{data[7]}', True, 'black'), (55 + 150, 540))       
    pygame.draw.circle(screen, 'white', (75 , 160), 60)
    screen.blit(font.render(f'{data[0]}', True, 'black'), (55 , 150))
    pygame.draw.circle(screen, 'white', (75 , 290), 60)
    screen.blit(font.render(f'{data[2]}', True, 'black'), (55 , 280))
    pygame.draw.circle(screen, 'white', (75 , 420), 60)
    screen.blit(font.render(f'{data[4]}', True, 'black'), (55 , 410))
    pygame.draw.circle(screen, 'white', (75 , 550), 60)
    screen.blit(font.render(f'{data[6]}', True, 'black'), (55 , 540))
    screen.blit(font.render(f'SPEED', True, 'dark gray'), (35, 70))
    screen.blit(font.render(f'HERTZ', True, 'white'), (180, 70))



# main repeating loop where we check for new arduino data and display onto a GUI if we have good new data
run = True
while run:
    screen.fill('black')
    # timer.tick(fps)
    if arduinoData.inWaiting() == 0:
        pass
    dataPacket = arduinoData.readline()
    dataPacket = str(dataPacket)
    draw_screen(parse_data(dataPacket))
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
    pygame.display.flip()
pygame.quit()

