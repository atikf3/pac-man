# Linux (Ubuntu-based): Compilation et lancement du projet

Se rendre sur ce site https://www.sfml-dev.org/download/sfml/2.5.0/ <br>
tout en bas de la page se trouve le code source, téléchargez le.<br>
et mettez le dans votre `/home/user/`<br>
Dans votre console:<br>
Pour installer la librairie SFML<br>
```bash
sudo apt -yq install libsfml-dev g++ build-essential libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libglew-dev libjpeg-dev libsndfile1-dev libopenal-dev cmake-gui
```

Ouvrez ensuite le cmake gui.<br>
<image src="https://preshing.com/images/cmake-gui-options.png"/><br>
Dans le premier input vous devez mettre le chemin du code source donc :<br>
/home/user/SFML-2.5.0<br>
Dans le deuxième input votre dossier de travail que vous pouvez choisir comme vous voulez. Mais des fichiers vont y être mis donc vous devrez le garder.<br>
Appuyez sur ```configure``` <br>
<b>Si Erreur</b><br>
Regardez dans la petite console du CMake GUI et regardez s'il ne manque pas une librairie à installer.<br>
Si <b>done</b> apparait c'est que c'est bon.<br>
<br>
<br>
Maintenant vous pouvez récupérer le git et pour lancer le projet il faut ces trois commandes:<br>
```g++ -c *.cpp```
<br>
```g++ *.o -o jeu -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system```
<br>
```./jeu```

<br>
Si vous rajoutez des fichiers .cpp il faut les rajouter dans la compilation.


 _src: [gh/Kravennagen/LittleBigGame](https://github.com/Kravennagen/LittleBigGame/blob/master/README.md)_