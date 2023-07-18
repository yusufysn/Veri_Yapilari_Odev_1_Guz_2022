Tum: derleme calistirma

derleme: 
	g++ -I ./include/ -o ./lib/DosyaOku.o -c ./src/DosyaOku.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/BagliListe.o -c ./src/BagliListe.cpp
	g++ -I ./include/ -o ./lib/YoneticiDugum.o -c ./src/YoneticiDugum.cpp
	g++ -I ./include/ -o ./lib/YoneticiListe.o -c ./src/YoneticiListe.cpp
	g++ -I ./include/ -o ./lib/Ekran.o -c ./src/Ekran.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/DosyaOku.o ./lib/Dugum.o ./lib/BagliListe.o ./lib/YoneticiDugum.o ./lib/YoneticiListe.o ./lib/Ekran.o ./src/main.cpp
 
calistirma:
	./bin/Test