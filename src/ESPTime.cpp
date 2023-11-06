
#include "ESPTime.h"
#include "esp_sntp.h"


tm ESPTime::_tm;
uint32_t ESPTime::_last_sync = 0;

void ESPTime::on_sync_handler(struct timeval *tv)
{
    _last_sync = unixtime();
}

int ESPTime::start(const char* tz, const char* server, int sync_interval_ms)
{
    sntp_set_time_sync_notification_cb(on_sync_handler);
    sntp_set_sync_interval(sync_interval_ms);
    configTzTime(tz, server);

    return 1;
}

int ESPTime::last_sync()
{
    if(_last_sync > 0)
        return unixtime() - _last_sync;

    return 0;
}

// int ESPTime::setSyncInterval(int interval_ms)
// {
//     sntp_set_sync_interval(interval_ms);
//     if(sntp_enabled())
//         sntp_restart();
    
//     return 1;
// }


tm* ESPTime::localtime()
{
    if(_last_sync>0)
    {
        time_t now = time(NULL);
        tm* tinfo = localtime_r(&now, &_tm);
        return tinfo;
    }
    
    return NULL;
}

tm* ESPTime::utc()
{
    if(_last_sync>0)
    {
        time_t now = time(NULL);
        tm* tinfo = gmtime_r(&now, &_tm);
        return tinfo;
    }

    return NULL;
}

uint32_t ESPTime::unixtime()
{
    return time(NULL);
}