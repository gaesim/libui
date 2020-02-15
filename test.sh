make
gcc ./main.c ./libui.a -framework SDL2 -framework SDL2_image -framework SDL2_ttf -I ./inc -F ./frmwrk -rpath `pwd`/frmwrk
./a.out