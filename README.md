# Screen Dimmer v1
Screen Dimmer adds translucent overlay over screen to reduce eye strain.
Unlike other color shifting programs, Screen Dimmer allows you to choose the color, opacity and when you want it on or off.

Features:
* choose your preferred color (nothing looks orange, unless you want it to be)
* choose your preferred opacity
* no timers so you can turn it on or off when you want
* once started the overlay doesn't change over time (depending on the time of day, sun, moon or planetary alignment)
* multi-monitor systems can choose which monitors to dim with independent color and opacity for each

red with .25 opacity\
![Screen Dimmer Screenshot](screenshot/screendimmer-screenshot-01.png?raw=true "Red")

green with .25 opacity\
![Screen Dimmer Screenshot](screenshot/screendimmer-screenshot-02.png?raw=true "Green")

blue with .25 opacity\
![Screen Dimmer Screenshot](screenshot/screendimmer-screenshot-03.png?raw=true "Blue")

black with .5 opacity\
![Screen Dimmer Screenshot](screenshot/screendimmer-screenshot-04.png?raw=true "Black")

---

**Installation Options (neither option requires install)**
* Binary
  * download bin\
`screendimmer` can be placed in any directory\
`.screendimmerrc` must be in home directory
* Compile
  * prerequisite\
libgtk-3-dev
  * download src and run g++ commands below (NOTE: backtick **not** single quote)\
``` g++ -s -Os -lGL -std=c++17 -c *.cpp `pkg-config --cflags --libs gtk+-3.0` ```\
``` g++ -s -Os -lGL -std=c++17 *.o `pkg-config --cflags --libs gtk+-3.0` -o screendimmer` ```
  * `screendimmer` can be placed in any directory\
`.screendimmerrc` must be in home directory

**Configuration**
* `.screendimmerrc`
  * `monitor.count` number of monitors (NOTE: '1' below is the monitor number)
  * `monitor.1.width` width of monitor resolution
  * `monitor.1.height` height of monitor resolution
  * `monitor.1.color` any hex color value\
example:
    * #000000 = black
    * #FF0000 = red
    * #00FF00 = green
    * #0000FF = blue
    * #FFFFFF = white
  * `monitor.1.opacity` opacity between 0-1\
example:
    * 0 = off
    * .5 = 1/2 transparent
    * 1 = completely solid
* default settings will be used if `.screendimmerrc` is not used
  * monitor.count = 1
  * monitor.1.width = 1920
  * monitor.1.height = 1080
  * monitor.1.color = #000000
  * monitor.1.opacity = .5

**Run Options**
  * Foreground
    * `./screendimmer start`
  * Background
    * `./screendimmer start &`
  * Disown
    * `./screendimmer start &`\
`disown`
  * Add to Launcher Favorites\
click to start\
click again to stop
    * move `.screendimmerrc` to home directory
    * create `/opt/screendimmer` directory
    * move `screendimmer` to `/opt/screendimmer/`
    * move `screendimmer.sh` to `/opt/screendimmer/`
    * move `screendimmer.desktop` to either `~/.local/share/applications/` or `/usr/share/applications/`
    * open launcher and add to favorites

**Stop**
* `./screendimmer stop`
