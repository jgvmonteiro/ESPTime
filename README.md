
[Tz.h](https://github.com/jgvmonteiro/ESPTime/blob/master/src/Tz.h) taken from https://github.com/nayarsystems/posix_tz_db/blob/master/zones.json.

    	
     	 
	#include <ESPTime.h>
    
	setup(){
		//Serial begin...
		//connect to wifi first...
		
		ESPTime::start(TZ_AMERICA_NEW_YORK);
	}
	
	loop(){
		
		tm* timeinfo = ESPTime::localtime();
		if(timeinfo!=NULL){ //is null until ntp server response
			Serial.println(timeinfo, "%A, %B %d %Y %H:%M:%S");
		}

		delay(1000);
	}    

    

