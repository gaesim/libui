make
gcc ./main.c ./libui.a -framework SDL2 -I ./inc -F ./frmwrk -rpath `pwd`/frmwrk
./a.out