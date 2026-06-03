import math
import time

from math import cos, sin

import serial
import pygame 

pygame.init()

WIDTH = 400
HEIGHT = 400
screen = pygame.display.set_mode([WIDTH, HEIGHT])

arduinoData = serial.Serial('com3', 9600)
timer = pygame.time.Clock()
fps = 60
data = [0, 0, 0, 0, 0, 0, 0, 0] 
font = pygame.font.Font('freesansbold.ttf', 24)

print(arduinoData)

