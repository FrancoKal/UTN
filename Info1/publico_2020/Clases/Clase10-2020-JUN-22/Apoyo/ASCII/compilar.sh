gcc -c creonummain.c    -o creonummain.o    -Wall
gcc -c creonummain_a.c  -o creonummain_a.o  -Wall
gcc -c creonumfunc.c    -o creonumfunc.o    -Wall
gcc -c creonumfunc_a.c  -o creonumfunc_a.o  -Wall
gcc -c creonumfunc_a2.c  -o creonumfunc_a2.o  -Wall


gcc creonummain.o   creonumfunc.o     -o cfn -Wall
gcc creonummain_a.o creonumfunc.o     -o cfn1 -Wall
gcc creonummain.o   creonumfunc_a.o   -o cfn2 -Wall
gcc creonummain_a.o creonumfunc_a.o   -o cfa -Wall
gcc creonummain_a.o creonumfunc_a2.o  -o cfa1 -Wall

rm *.o
