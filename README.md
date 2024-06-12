# Pdfgen

 Ce projet est un application permetant de créer des fichiers au format pdf, en dépendant d'un "Questionnaire" rempli par l'utilisateur, d'autres fichiers pdf (pour pouvoir fusionner des fichiers PDF) ou la création de facture par exemple.

## Sommaire

- [Introduction](#introduction)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Amélioration futures](#Amélioration-futures)

## Introduction

Donnez une vue d'ensemble de votre projet, expliquant son but et ce qu'il accomplit.

Le début du projet à commencé avec comme objetcif en tête de faire une application optimisée en c++, mais il a vite dériver pour un meilleur maintient dans le temps et la modularité. En effet le projet est en cour de developpement encore aujourd'hui car il s'agit maintenant de créer une librairie en C++ basée sur la SFML pour pouvoir créer des application, très facilement et rapidement.

## Fonctionnalités

Les fonctionnalitéss principales actuelles de l'application sont les suivante :

- l'ajout rapide de widgets, permettant une interface graphique rapide et fluide a faire. Les widgets pouvant etre ajouter sont les suivants :
    - **Texte** : un texte simple pour pouvoir afficher n'importe quel phrase.
    - **Image** : une image de n'importe quel type, n'importe quelle taille.
    - **GIF** : une petite vidéo rapide.

- Les widgets possèdent aussi des variables permettant de faire plusieurs choses :
    - Un Widget peut provoquer un changement de curseur si la souris passe dessus.
    - Un Widget, si la variable "can_move" est mis a "true", peut se déplacer.
    - Un Widget peut avoir plein de variables différentes et peuvent changer.
    - Un Widget peut etre aussi un bouton, et possède des "actions" appropriées pour chaque boutton.

## Installation

Expliquez comment installer votre projet. Par exemple :

```bash
git clone git@github.com:DarkWhige/pdfgen.git
cd pdfgen
make
```

## Utilisation

```bash
./pdfgen
```

Cela ouvrira la page principale de l'application, actuellement cela donnera la future page de chargement de l'application

## Améliorations futures

Comme ameilorations futures, il pourrait y avoir les Widgets suivants :
- Un widget video, pour ajouter un "Lecteur vidéo" pour montrer le fonctionnement de l'application.
- Un widget d'editeur de texte, pour pouvoir faire un espace ou l'utilisateur peut écrire.
- Un widget d'éditeur de texte, pour pouvoir faire un espace ou l'utilisateur peut écrire mais avec d'autres spécificités, comme le fait de pouvoir ecrire en italique, en gras etc...
- Un widget dropdown, pour pouvoir avoir un menu dropdown
- 

- Avoir la possibilité de zommer dans la fenêtre
- Avoir la possibilité de scroller dans la fenêtre
- Avoir un changement de thème
