import requests, json, time

FILE = "src/Tz.h"
URL = "https://raw.githubusercontent.com/nayarsystems/posix_tz_db/master/zones.json"


r = requests.get(URL)
if r.status_code==200:
    tz_json = json.loads(r.content)
    file = open(FILE, 'w')
    file.write("\n\n\n//"+str(int(time.time()))+"\n\n")
    for key in tz_json:
        name = "TZ"
        for s in key.split("/"):
            name += "_" + s.replace("+", "_P").replace("-", "_M")
        file.write("#define " + name.upper() + " \"" + tz_json[key] + "\"\n")

    file.close()
    print("new", FILE, "created")
else:
    print("request failed, status", r.status_code)


