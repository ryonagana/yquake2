/**
 *  @section LICENSE
 *
 *  GPH Controls
 *  Copyright (C) 2011 Scott R. Smith
 *  All Rights Reserved.
 *
 *  @section LOCATION
 */

#ifndef CGPH_H
#define CGPH_H

#include <SDL.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/soundcard.h>

enum {
    GPH_NONE=0,
    GPH_RELEASED_TO_PRESSED,
    GPH_PRESSED,
    GPH_PRESSED_TO_RELEASED,
    GPH_RELEASED
};

#define GPH_MAX_BUTTONS 32
#define GPH_BUTTON(X)           (1<<X)

#if defined(CAANOO)
#include <linux/input.h>
#endif

#define GPH_UP                  0
#define GPH_UP_LEFT             1
#define GPH_LEFT                2
#define GPH_DOWN_LEFT           3
#define GPH_DOWN                4
#define GPH_DOWN_RIGHT          5
#define GPH_RIGHT               6
#define GPH_UP_RIGHT            7
#define GPH_START               8   // Caanoo HOME
#define GPH_SELECT              9   // Cannoo HELP2
#define GPH_L                   10
#define GPH_R                   11
#define GPH_A                   12
#define GPH_B                   13
#define GPH_X                   14
#define GPH_Y                   15
#define GPH_VOL_UP              16
#define GPH_VOL_DOWN            17
#define GPH_PUSH                18  // Caanoo only
#define GPH_HELP1               19  // Caanoo only

#define GPH_AB                  20
#define GPH_AX                  21
#define GPH_AY                  22
#define GPH_BX                  23
#define GPH_BY                  24
#define GPH_XY                  25

#if defined(WIZ)
#define VOLUME_MIN              0
#define VOLUME_MAX              100
#define VOLUME_CHANGE_RATE      2
#define VOLUME_NOCHG            0
#define VOLUME_DOWN             1
#define VOLUME_UP               2
#define VOLUME_TIME_RATE        20
#endif

void    GPH_Close           ( void );
int8_t  GPH_Open            ( void );
void	GPH_Input           ( void );

void    GPH_ReadButtons     ( void );
#if defined(CAANOO)
void    GPH_ReadAnalog      ( void );
#endif
#if defined(WIZ)
void    GPH_AdjustVolume    ( uint8_t direction );
#endif
int8_t  GPH_GetButttonState ( uint32_t button );

extern SDLKey gph_map[GPH_MAX_BUTTONS];

#endif // CGPH_H

