#ifndef IO_H
#define IO_H

#include <global.h>
#include <hero.h>

extern Hero hero;
extern void shoot();

void updateInput(sf::Event event);

#endif
