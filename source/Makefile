#
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17 

__start__: dron.out
	./dron.out

dron.out: obj/Dr3D_gnuplot_api.o obj/wektor_macierz.o obj/main.o
	g++ -o dron.out obj/main.o obj/Dr3D_gnuplot_api.o -lpthread

obj/main.o: src/main.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh 
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

obj/wektor_macierz.o: src/wektor_macierz.cpp src/wektor.cpp src/macierz.cpp\
		inc/macierz.hh inc/wektor.hh
	g++ ${CPPFLAGS} -o obj/wektor_macierz.o src/wektor_macierz.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

clear:
	rm dron.out obj/main.o obj/Dr3D_gnuplot_api.o
