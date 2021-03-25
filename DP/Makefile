main: compiled/main.o compiled/ConcreteCreatorDiesel.o compiled/ConcreteCreatorEssence.o compiled/VoitureFactory.o compiled/VoitureDiesel.o compiled/VoitureEssence.o compiled/Voiture.o
	g++ -Wall -std=c++11 -o main compiled/main.o compiled/ConcreteCreatorDiesel.o compiled/ConcreteCreatorEssence.o compiled/VoitureFactory.o compiled/VoitureDiesel.o compiled/VoitureEssence.o compiled/Voiture.o
	doxygen Doxyfile
compiled/main.o: main.cpp
	g++ -Wall -std=c++11 -c main.cpp -o compiled/main.o

compiled/ConcreteCreatorDiesel.o: ConcreteCreatorDiesel.cpp
	g++ -Wall -std=c++11 -c ConcreteCreatorDiesel.cpp -o compiled/ConcreteCreatorDiesel.o 

compiled/ConcreteCreatorEssence.o: ConcreteCreatorEssence.cpp
	g++ -Wall -std=c++11 -c ConcreteCreatorEssence.cpp -o compiled/ConcreteCreatorEssence.o 

compiled/VoitureFactory.o: VoitureFactory.cpp
	g++ -Wall -std=c++11 -c VoitureFactory.cpp -o compiled/VoitureFactory.o

compiled/VoitureDiesel.o: VoitureDiesel.cpp
	g++ -Wall -std=c++11 -c VoitureDiesel.cpp -o compiled/VoitureDiesel.o

compiled/VoitureEssence.o: VoitureEssence.cpp
	g++ -Wall -std=c++11 -c VoitureEssence.cpp -o compiled/VoitureEssence.o

compiled/Voiture.o: Voiture.cpp
	g++ -Wall -std=c++11 -c Voiture.cpp -o compiled/Voiture.o 

clean :
	rm -rf compiled/* main 