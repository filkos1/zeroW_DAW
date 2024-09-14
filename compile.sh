#in this hell script there will be all shell C compiler commands and maybe some misc stuff

echo "Compiling with an output in $1"
gcc -o "$1" ./main.c -lbcm2835 -lwiringPiDev