

#pragma once



#include <Arduino.h>
#include <time.h>
#include "Tz.h"


class ESPTime
{
private:
    /* data */
    static tm _tm;
    static uint32_t _last_sync;

    static void on_sync_handler(struct timeval *tv);

public:

    /**/
    static int start(const char* tz, const char* server = "pool.ntp.org", int sync_interval_ms = 1000l*3600*4);

    /*seconds elasped since last ntp response*/
    static int last_sync();

    /*returns NULL if doesnt have valid timestamp from ntp server yet*/
    static tm* localtime();
    
    /*returns NULL if doesnt have valid timestamp from ntp server yet*/
    static tm* utc();

    /*unix timestamp*/
    static uint32_t unixtime();

};

