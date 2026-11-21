# Follow – Logiciel de comparaison de textes

## Présentation

Follow est un logiciel permettant de comparer deux versions d'un document afin d'identifier et de visualiser les modifications apportées entre une version de référence et une nouvelle version.

L'objectif est de mettre en évidence les différences entre les deux textes tout en recherchant un alignement optimal afin de minimiser le nombre d'opérations nécessaires pour passer d'une version à l'autre.

## Fonctionnalités

- Chargement d'un texte de référence.
- Chargement d'une nouvelle version du document.
- Comparaison automatique des deux textes.
- Détection des insertions, suppressions et remplacements de mots.
- Mise en évidence des différences par un code couleur :
  - 🔴 Rouge : mots supprimés.
  - 🟢 Vert : mots insérés.
  - 🔵 Bleu : mots remplaçant un mot de la référence.
- Conservation de la mise en page du nouveau document.
- Ouverture des fichiers depuis le menu ou la ligne de commande.
- Fenêtre « À propos » présentant les informations du logiciel.

## Principe de fonctionnement

Le logiciel compare les mots des deux documents en recherchant un alignement qui minimise le nombre d'opérations d'édition : insertion, suppression et remplacement.

La ponctuation et les caractères spéciaux sont également pris en compte, tandis que les différences de mise en page ne sont pas considérées.

## Technologies

- **Langage de programmation :** C
- **Interface graphique (IHM) :** GTK
- **Conception de l'interface :** Glade
- **Algorithmes :** Alignement de textes et calcul des différences
- **Gestion des fichiers :** Lecture et manipulation de fichiers texte
- **Outils :** GCC, Git et GitLub

## Auteur

SELMI Manar 
