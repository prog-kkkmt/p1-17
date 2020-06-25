import pygame

def hit(x1, y1, x2, y2, z1, z2):
    if x1 > x2 - z1 and x1 < x2 + z2 and y1 > y2 - z1 and y1 < y2 + z2:
        return 1
    else:
        return 0
        
pygame.init()

window = pygame. display.set_mode((600, 400))
screen = pygame.Surface((600, 600))
player = pygame.Surface((110, 40))
target = pygame.Surface((40, 60))
arrow = pygame.Surface((10, 30))
count = 0

img_allien = pygame.image.load('allien.png')
img_ship = pygame.image.load('ship.png')
img_space = pygame.image.load('space.jpg')
img_hit = pygame.image.load('hit.png')

x_player = 255
y_player = 360

x_target = 0
y_target = 0

x_arrow = 700
y_arrow = 700

font = pygame.font.SysFont('serif', 20)
player.set_colorkey((0,0,0))
arrow.set_colorkey((0,0,0))
target.set_colorkey((0,0,0))

done = False
right = True
strike = False

while done == False:
    for a in pygame.event.get():
        if a.type == pygame.QUIT:
            done == True
        if a.type == pygame.KEYDOWN and a.key == pygame.K_w:
            y_player -= 15
        if a.type == pygame.KEYDOWN and a.key == pygame.K_s:
            y_player += 15
        if a.type == pygame.KEYDOWN and a.key == pygame.K_a:
            x_player -= 15
        if a.type == pygame.KEYDOWN and a.key == pygame.K_d:
            x_player += 15
        if a.type == pygame.KEYDOWN and a.key == pygame.K_SPACE:
            if strike == False:
                strike = True
                x_arrow = x_player + 55
                y_arrow = y_player - 30

    if right:
        x_target += 1
        if x_target > 540:
            x_target -= 1
            right = False
    else:
        x_target -= 1
        if x_target < 0:
            x_target += 1
            right = True

    if strike:
        y_arrow -= 1.5
        if y_arrow < 0:
            strike = False
            x_arrow = 700
            y_arrow = 700

    if hit(x_arrow, y_arrow, x_target, y_target, 10, 30):
        count += 1
        strike = False
        x_arrow = 700
        y_arrow = 700

    string = font.render('Score: '+str(count), 0, (250, 0, 0))
    target.blit(img_allien, (0, 0))
    player.blit(img_ship, (0, 0))
    arrow.blit(img_hit, (0, 0))
    screen.blit(img_space, (0, 0))
    screen.blit(player, (x_player, y_player))
    screen.blit(target, (x_target, y_target))
    screen.blit(arrow, (x_arrow, y_arrow))
    screen.blit(string, (0, 60))
    window.blit(screen, (0, 0))
    pygame.display.update()

pygame.quit()
