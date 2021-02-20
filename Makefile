main: main.o ConcreteCreatorDiesel.o ConcreteCreatorEssence.o VoitureFactory.o VoitureDiesel.o VoitureEssence.o Voiture.o
	g++ -Wall -std=c++11 -o main main.o ConcreteCreatorDiesel.o ConcreteCreatorEssence.o VoitureFactory.o VoitureDiesel.o VoitureEssence.o Voiture.o
main.o: main.cpp
	g++ -Wall -std=c++11 -c main.cpp
ConcreteCreatorDiesel.o: ConcreteCreatorDiesel.cpp
	g++ -Wall -std=c++11 -c ConcreteCreatorDiesel.cpp 
ConcreteCreatorEssence.o: ConcreteCreatorEssence.cpp
	g++ -Wall -std=c++11 -c ConcreteCreatorEssence.cpp 
VoitureFactory.o: VoitureFactory.cpp
	g++ -Wall -std=c++11 -c VoitureFactory.cpp 
VoitureDiesel.o: VoitureDiesel.cpp
	g++ -Wall -std=c++11 -c VoitureDiesel.cpp 
VoitureEssence.o: VoitureEssence.cpp
	g++ -Wall -std=c++11 -c VoitureEssence.cpp 
Voiture.o: Voiture.cpp
	g++ -Wall -std=c++11 -c Voiture.cpp 

clean :
	rm -rf *.o main