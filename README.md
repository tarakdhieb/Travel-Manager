# Travel-Manager
# La gestion d’une agence de voyage
## Introduction :
Ce programme est écrit en langage C .Il permet de voir tous les voyages disponibles entre deux dates et gère les dates des voyages.
Nous avons utilisé la notion de liste chaînée pour gagner de l'espace et un fichier pour stocker tous les inforations. Ce programme effectue les tâches suivantes :

● Ajouter un voyage

● Afficher la description d’un voyage.

● Supprimer un voyage.

● Modifier un voyage.

● Recherche des voyages disponibles selon des dates précises.

### Les nouveaux types utilisés :
j'ai créé 2 types dans ce programme qui sont :
-Date :
Qui a 3 champs jj:jours, mm:moins, aa:ans.
-Voyage :
Qui a 8 champs qui sont id, destination, description, nbPlaces, nbPlacesRestantes,dateDebut, dateFin et suivant.

### Fonctions utilisées :
Tous d'abord, j'ai declaré un pointeur comme une paramètre global, qui pointe à l'adresse du 1er élément de la liste chaînée et j'ai créé 7 fonctions dans ce programme qui sont :
- Saisie :
Qui permet de retourner une date de types Date sous la forme jj:mm:aa .
- AjouterVoyage :
Qui prend l'id, la Destination, la Description, Nombre de places, la dateDebut et la dateFin et permet de l'ajouter dans la liste chaineé.
- SupprimerVoyage :
Qui prend l'id pour le suuprimer, mais lorsque ce id est introuvable, il retourne un message "le voyage est introuvable"
- Enregistrer :
Aprés la suppresion d'un voyage, cette fonction enregistre tous les donneés de la liste chaineé dans le fichier voyage.txt. 
- ModifierVoyage :
Qui prend l'id du voyage.S'il existe ce id, il affiche toutes les données anciens et prend les nouveaux.
- AfficherDescriptionVoyage :
Qui prend l'id du voyage et afficher leur description.
- AfficherVoyageDisponible :
Qui prend deux dates et afficher les voyages qui sont disponible entre ces deux dates.


