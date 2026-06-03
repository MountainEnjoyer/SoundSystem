import math
import time

from math import cos, sin

import serial # pip install pyserial
import pygame # pip install pygame

pygame.init()

WIDTH = 300
HEIGHT = 620
screen = pygame.display.set_mode([WIDTH, HEIGHT])

arduinoData = serial.Serial('com3', 9600)
timer = pygame.time.Clock()
fps = 60
w, h = 3, 7
data = [[0 for x in range(w)] for y in range(h)] 
font = pygame.font.Font('freesansbold.ttf', 24)

def parse_data(fulldata):
    print(fulldata)

    x = 0
    y = 0
    lenght = len(fulldata) - 5

    for i in range(2 , lenght):
    

        if fulldata[i] != '-' or fulldata[i] != '/':
            data[x][y] = fulldata[i]
            y =+ 1
            print(data[x])
        else :
            x += 1
            y=0
        print(i)
    print(data)
    return(data)

def draw_screen(data):

    screen.blit(font.render(f'SYNTHETISER', True, 'red'), (67, 10))

    for i in range(2):
        if i == 1:
            pygame.draw.circle(screen, 'dark gray', (75 + 150 * i, 160), 60)
            screen.blit(font.render(f'{data[1]}', True, 'black'), (35 + 150 * i, 150))
            pygame.draw.circle(screen, 'dark gray', (75 + 150 * i, 290), 60)
            screen.blit(font.render(f'HERTZ', True, 'black'), (35 + 150 * i, 280))
            pygame.draw.circle(screen, 'dark gray', (75 + 150 * i, 420), 60)
            screen.blit(font.render(f'HERTZ', True, 'black'), (35 + 150 * i, 410))
            pygame.draw.circle(screen, 'dark gray', (75 + 150 * i, 550), 60)
            screen.blit(font.render(f'HERTZ', True, 'black'), (35 + 150 * i, 540))
        elif i == 0:
            pygame.draw.circle(screen, 'white', (75 + 150 * i, 160), 60)
            screen.blit(font.render(f'SPEED', True, 'black'), (35 + 150 * i, 150))
            pygame.draw.circle(screen, 'white', (75 + 150 * i, 290), 60)
            screen.blit(font.render(f'SPEED', True, 'black'), (35 + 150 * i, 280))
            pygame.draw.circle(screen, 'white', (75 + 150 * i, 420), 60)
            screen.blit(font.render(f'SPEED', True, 'black'), (35 + 150 * i, 410))
            pygame.draw.circle(screen, 'white', (75 + 150 * i, 550), 60)
            screen.blit(font.render(f'SPEED', True, 'black'), (35 + 150 * i, 540))
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

