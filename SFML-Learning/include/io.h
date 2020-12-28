#ifndef IO_H
#define IO_H

#include <global.h>
#include <hero.h>

extern Hero hero;
extern bool gameover;
extern void shoot();
extern void quit();
extern void reset();

void updateInput(sf::Event event);
void updateInputGameOver(sf::Event event);

#endif
