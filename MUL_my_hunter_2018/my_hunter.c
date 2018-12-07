/*
** EPITECH PROJECT, 2018
** create_window
** File description:
** create a window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>

int rande(int i)
{
    switch (i) {
        case 0:
            i = 400;
            break;
        case 100:
            i = 300;
            break;
        case 200:
            i = 500;
            break;
        case 300:
            i = 200;
            break;
        case 500:
            i = 0;
            break;
        case 400:
            i = 100;
            break;
    }
    return (i);
}

sfIntRect move_rect(sfIntRect rect, int offset, int max_value)
{
    if (rect.left == max_value)
        rect.left = 0;
    else
        rect.left = rect.left + offset;
    return (rect);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') { 
            write(1, "Rules : you have to shoot on the duck with your", 46);
            write(1, " left click mouse.\nEverytime you shoot it, it ", 46);
            write(1, "will go faster.\nYou only have 3 lifes.\nWhen you", 48);
            write(1, " miss a shot, you loose one life.\nIf you miss ", 46);
            write(1, "3 times, it's game over.\n", 25);
        }
        return EXIT_FAILURE;
    }
    float j = 00.003;
    int i = 0;
    int l = 3;
    int k = 0;
    int m = 0;

    sfEvent event;

    sfMusic* music;
    sfMusic* back;
    sfMusic* miss;

    sfClock* sound;
    sfTime time_sound;
    float second;
    sound = sfClock_create();

    sfClock* timer;
    sfTime time;
    float seconds;
    timer = sfClock_create();

    sfClock* moove;
    sfTime move;
    float sec;
    moove = sfClock_create();

    sfTexture* texture;
    sfSprite *sprite;

    sfTexture* balle;
    sfSprite *bullet;

    sfTexture* gameover;
    sfSprite *gover;

    sfVector2f siize;
    siize.x = 0.10;
    siize.y = 0.08;

    sfVector2f random;
    random.x = -110;
    random.y = 0;

    sfVector2f size;
    size.x = 0.68;
    size.y = 0.73;

    sfVector2f vector;
    vector.x = 1;
    vector.y = 0;

    sfVector2f bottom;
    bottom.x = 530;
    bottom.y = 650;

    sfTexture* duck;
    sfSprite *duckk;

    sfRenderWindow *window;

    sfVideoMode video_mode;

    video_mode.width = 1280;
    video_mode.height = 769;
    video_mode.bitsPerPixel = 32;

    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;


    window = sfRenderWindow_create(video_mode, "Hunt", sfDefaultStyle, NULL);

    gameover = sfTexture_createFromFile("gameover.png", NULL);
    gover = sfSprite_create();
    sfSprite_setTexture(gover, gameover, sfTrue);
    sfSprite_setScale(gover, size);

    balle = sfTexture_createFromFile("balle.png", NULL);
    bullet = sfSprite_create();
    sfSprite_setTexture(bullet, balle, sfTrue);
    sfSprite_setScale(bullet, siize);

    texture = sfTexture_createFromFile("background.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);


    duck = sfTexture_createFromFile("duck.png", NULL); 
    duckk = sfSprite_create();
    sfSprite_setTexture(duckk, duck, sfTrue);

    music = sfMusic_createFromFile("musique.ogg");
    miss = sfMusic_createFromFile("miss.ogg");
    back = sfMusic_createFromFile("backsound.ogg");

    sfMusic_setVolume(back, 10);
    sfMusic_setVolume(miss, 30);
    sfMusic_setVolume(music, 30);

    sfMusic_play(back);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            switch (event.type) {
                case sfEvtClosed:
                    sfRenderWindow_close(window);
                    break;
                case sfEvtMouseButtonPressed:
                    if (event.mouseButton.x > i &&
                        event.mouseButton.x < i + 110 &&
                        event.mouseButton.y > random.y &&
                        event.mouseButton.y < random.y + 110) {
                        sfMusic_play(music);
                        random.y = rande(random.y);
                        sfSprite_setPosition(duckk, random);
                        j = j - 0.0002;
                        i = -110;
                    }
                    else {
                        if (l > 0) {
                            l--;
                            sfMusic_play(miss);
                        }
                    }
                    break;
                defaut:
                    break;
            }
        }
        sfSprite_setTextureRect(duckk, rect);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, duckk, NULL);
        while (m < l) {
            sfSprite_setPosition(bullet, bottom);
            sfRenderWindow_drawSprite(window, bullet, NULL);
            bottom.x = bottom.x + 75;
            m++;
        }
        bottom.x = 530;
        m = 0;
        time = sfClock_getElapsedTime(timer);
        move = sfClock_getElapsedTime(moove);
        time_sound = sfClock_getElapsedTime(sound);
        seconds = time.microseconds / 1000000.0;
        sec = move.microseconds / 1000000.0;
        second = time_sound.microseconds / 1000000.0;
        if (second > 4) {
            sfMusic_play(back);
            sfClock_restart(sound);
        }
        if (l == 0) {
              sfRenderWindow_drawSprite(window, gover, NULL);
        }
        sfRenderWindow_display(window);
        if (sec > j) {
            sfSprite_move(duckk, vector);
            i++;
            sfClock_restart(moove);
        }
        if (i == 1389) {
            random.y = rande(random.y);
            sfSprite_setPosition(duckk, random);
            i = -110;
        }
        if (seconds > 0.25) {
            rect = move_rect(rect, 110, 220);
            sfClock_restart(timer);
        }
    }    
    sfRenderWindow_destroy(window);
    return (0);
}
