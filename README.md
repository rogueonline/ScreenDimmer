# Screen Dimmer v1
Screen Dimmer adds translucent overlay over screen to reduce eye strain without turning your screen orange like other color shifting programs.
Unlike similar programs, Screen Dimmer allows you to choose the color, opacity, and when you want to use it.

Features:
* **not** on a timer so you can turn it on or off when you want
* you get to choose your preferred color (nothing looks orange, unless you want it to be)
* once started the overlay doesn't change over time (depending on the time of day, sun, moon, planetary positions)
* multi-monitor setups can choose which monitors to apply overlay with independent color and opacity for each

red with .25 opacity\
![Screen Dimmer Screenshot](screenshot/screendimmer-screenshot-01.png?raw=true "Red")\

green with .25 opacity\
![Screen Dimmer Screenshot](screenshot/screendimmer-screenshot-02.png?raw=true "Green")\

blue with .25 opacity\
![Screen Dimmer Screenshot](screenshot/screendimmer-screenshot-03.png?raw=true "Blue")\

black with .5 opacity\
![Screen Dimmer Screenshot](screenshot/screendimmer-screenshot-04.png?raw=true "Black")\

**Installation Options (neither option requires install)**
* Binary
  * download bin\
`screendimmer` can be placed in any directory\
`.screendimmerrc` must be in home directory
* Compile
  * prerequisite\
libgtk-3-dev
  * download src and run g++ commands below (NOTE: backtick **not** single quote)\
``` g++ -lGL -std=c++17 -c *.cpp `pkg-config --cflags --libs gtk+-3.0` ```\
``` g++ -lGL -std=c++17 *.o `pkg-config --cflags --libs gtk+-3.0` -o screendimmer` ```
  * `screendimmer` can be placed in any directory\
`.screendimmerrc` must be in home directory

**Configuration**
* `.screendimmerrc` (must be in home directory)
  * `monitor.count` number of monitors (NOTE: '1' below is the monitor number)
  * `monitor.1.width` width of monitor resolution
  * `monitor.1.height` height of monitor resolution
  * `monitor.1.color` color as hex value\
#000000 = black\
#FF0000 = red\
#00FF00 = green\
#0000FF = blue\
#FFFFFF = white
  * `monitor.1.opacity` opacity between 0-1\
0 = off\
.5 = 1/2 transparent\
1 = completely solid

**Run Screen Dimmer**
* `./screendimmer`
