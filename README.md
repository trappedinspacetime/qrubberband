# qrubberband
For those who use `X server` and `compiz window manager`  there is a glitch that prevents proper drawing of rectangle ( rubberbanding ) on the screen while dragging the mouse ( moving mouse with left button pressed).

I conconcted it from the info I found on the net and QT documentation. It works with **miam** screenshot tool. 
It's based on QT4.

To build it on Ubuntu you need to have QT4 installed. 
First clone this repository:

     git clone https://github.com/trappedinspacetime/qrubberband.git
     cd qrubberband
If you also have QT5, you can switch to QT4 via environment variable:

     export QT_SELECT=4
then check version of the `qmake` if it switched to 4.x:

     qmake -v
if it's OK:

     qmake -project
     qmake -makefile
     make
run it like 

     ./qrubberband
and drag the screen area, it will print the result in the following format`wxh+x+y`, **x** and **y** are the starting coordinates.

You can copy it to `/usr/local/bin/` via:

     sudo cp qrubberband /usr/local/bin/
And you can run it with **miam** like:

     maim  -g $(qrubberband) test.png

I use it to translate text with **tesseract-ocr**. Here is my oneliner `bash` command:

     text=$(maim -g $(qrubberband)  | tesseract  stdin stdout -l eng | head -c -1 )  ; notify-send --icon=info "$text" "$(wget -U "Mozilla/5.0" -qO - "http://translate.googleapis.com/translate_a/single?client=gtx&sl=auto&tl=tr&dt=t&q=$(echo $text | sed "s/[\"'<>]//g")" | sed "s/,,,0]],,.*//g" | awk -F'"' '{print $2, $6}')" ; echo "$text" ;
    
