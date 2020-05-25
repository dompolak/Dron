#
#
CPPFLAGS = -c -g -Iinc -Wall -pedantic -std=c++17

__start__: dron.out
	./dron.out

dron.out: obj/Dr3D_gnuplot_api.o obj/wektor_macierz.o obj/dron.o \
	obj/main.o
	g++ -o dron.out obj/wektor_macierz.o obj/Dr3D_gnuplot_api.o\
	 obj/main.o obj/dron.o -lpthread

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

obj/wektor_macierz.o: src/wektor_macierz.cpp src/wektor.cpp src/macierz.cpp\
	inc/macierz.hh inc/wektor.hh
	g++ ${CPPFLAGS} -o obj/wektor_macierz.o src/wektor_macierz.cpp

obj/dron.o: src/dron.cpp inc/dron.hh inc/wirnik
	g++ ${CPPFLAGS} -o obj/dron.o src/dron.cpp

obj/main.o: src/main.cpp inc/dron.hh inc/dno.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

inc/dron.hh: inc/inter_rysowania.hh
	touch inc/bryla.hh inc/prostopadloscian.hh inc/inter_drona.hh \
	inc/dron.hh

inc/wirnik: inc/inter_rysowania.hh
	touch inc/bryla.hh inc/graniastoslup6.hh inc/wirnik.hh

inc/dno: inc/inter_rysowania.hh	
	touch inc/powierzchnia.hh inc/dno.hh

inc/tafla: inc/inter_rysowania.hh	
	touch inc/powierzchnia.hh inc/tafla.hh

clear:
	rm dron.out obj/*.o
