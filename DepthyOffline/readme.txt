latest version on https://github.com/panrafal/depthy is not as up-to-date as a site version (http://depthy.me)
So a rip of a site is used instead.

"depthy [build, 2016.09.03].zip" contains build of https://github.com/panrafal/depthy

"depthy" contains a Web rip of http://depthy.me site. It is more up-to-date and WebM video export actually works.

For some reason opening an app through index.html works badly on Chrome, but great on FireFox and QWebEngine.
On Chrome export options don't work, on Firefox export options do work (except for WebM export).
On QWebEngine everything works perfectly.

Instructions on building https://github.com/panrafal/depthy, just in case.
1. Install Node.js (npm comes with it as well);
2. open cmd and type:
   npm install npm -g
   to have latest version of npm;
3. install Ruby (there's a RubyInstaller version on the net);
4. open cmd and type:
   gem update --system
   to update Ruby.
   Then type:
   gem install compass
   to install Compass;
5. in cmd type:
   npm install -g grunt-cli bower
   to install Grunt and Bower;
6. now in cmd change your directory to your project directory (depthy folder where package.json resides)
   like so: cd Path\To\Your\Directory
   and type:
   npm install
   after that type:
   bower install
   that will prepare files for building;
7. after all that type:
   grunt build
   after that you'll have builded depthy in "dist" folder.
Keep in mind that repo version has a bug with exporting WebM video.