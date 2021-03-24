# BE Bestioles groupe 2

## Membres du groupe :
* DIOURI Yasmine
* FERNANDES Agathe
* UNG Théophile
* SPRIET Thibault

## Résumé du projet
A partir d'un cahier des charges fonctionnel et d'une situation initiale, nous avons implémenté une **simulation d'ecosystème** en C++. Cette simulation 
représente des bestioles évoluant au sein d'un milieu contenu dans un espace clos. Ces bestioles ont des attributs spécifiques :  
* vitesse
* position
* durée de vie
* ...  

peuvent intéragir entre elles :  
* collision
* détection  

Enfin chaque bestiole est dotée d'un comportement particulié :  
* Kamikaze
* Grégaire
* Peureuse
* Prévoyante  

et peut être augmentée grâce à des capteurs et accessoires :
* Yeux
* Oreilles
* Nageoires
* Carapace
* Camouflage  

Pour finir le client peut lancer la simulation avec la configuration qu'il souhaite (nombre de bestioles et pourcentage de chaque comportement).

## Installer / Compiler le projet
Tous les codes sources (.h et .cpp) nécessaire à la compilation sont présents sur ce repo.

1. Installer le projet  

Soit via protocole **https** : ```git clone https://github.com/thibaultspriet/CPP_projects.git```  

Soit via protocole **ssh** : ```git clone git@github.com:thibaultspriet/CPP_projects.git```  

2. Compiler le projet  
Pour compiler le projet, vous aurez besoin d'un Makefile. Nous vous proposons un exemple de [Makefile](BE/Makefile) mais il y aura certainement quelques adaptations à faire 
selon la configuration de votre machine et surtout l'emplacement de certains fichiers sources.  
Ainsi les principaux changements à apporter sont :
* Au niveau du tag main : -L /opt/X11/lib => changer le chemin avec le chemin où se trouve X11/lib sur votre machine
* Au niveau de chaque tag :  -I /opt/X11/include => changer le chemin avec le chemin où se trouve X11/lib sur votre machine  

Une fois les changements effectués, pour tester que cela fonctionne vous pouvez supprimer le fichier [main](BE/main) que nous vous fournissons : ```make clean``` puis vous pourrez compiler le projet : ```make```  

3. Lancer la simulation

Si la compilation a fonctionné pour vous, il est temps de lancer la simulation. Pour cela vous avez différentes options :
* ```./main``` pas d'arguments passés au programme, la simulation est lancée avec 20 bestioles au départ et les 4 comportements sont équireprésentés.
* ```./main <nombre créature> <pourcentage kamikaze> <pourcentage grégaire> <pourcentage peureuse> <pourcentage prévoyante>``` dans ce cas on passe 5 arguments au programme. Le premier est le nombre de bestioles que l'on souhaite à l'initialisation. Les 4 arguments suivants correspondent au pourcentage souhaité d'un certain comportement. A noter que ces arguments de pourcentage sont des entiers compris entre 0 et 100.
* ```./main <nombre créature> <pourcentage kamikaze> <pourcentage grégaire> <pourcentage peureuse> <pourcentage prévoyante> <chemin fichier>``` ce dernier cas est identique au précédent avec en plus l'évolution de la population qui est enregistrée dans un fichier .csv

## Documentation

Enfin, une documentation du code source est disponible. Ainsi chaque classe a sa propre documentation. Celle-ci a été généré avec doxygen et le format html se trouve [ici](BE/documentation/html). En ouvrant [index.html](BE/documentation/html/index.html) sur votre localhost, vous pourrez visionner l'ensemble de la documentation.
