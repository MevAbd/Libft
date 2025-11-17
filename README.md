# 📚 Libft

**Libft** est une bibliothèque C personnalisée développée dans le cadre du cursus 42. Elle contient une réimplémentation de fonctions standards de la libc ainsi que des fonctions supplémentaires utiles pour la manipulation de chaînes, de mémoire et de listes chaînées.

## 📋 Table des matières

- [Compilation](#-compilation)
- [Tests](#-tests)
- [Structure du projet](#-structure-du-projet)
- [Fonctions disponibles](#-fonctions-disponibles)
- [Bonus](#-bonus)

## 🔨 Compilation

### Compilation standard (fonctions obligatoires)
```bash
make
```

### Compilation avec bonus (listes chaînées)
```bash
make bonus
```

### Nettoyage
```bash
make clean      # Supprime les fichiers objets (.o)
make fclean     # Supprime les fichiers objets et la bibliothèque
make re         # Nettoie et recompile tout
```

## 🧪 Tests

Le projet inclut un testeur complet qui vérifie toutes les fonctions avec des cas limites approfondis.

### Exécuter les tests

```bash
make test
```

Cette commande :
1. Compile la bibliothèque avec bonus
2. Compile le testeur
3. Exécute automatiquement tous les tests (225 tests au total)

### Résultat attendu

Vous verrez un affichage organisé par sections avec :
- ✓ en vert pour les tests réussis
- ✗ en rouge pour les tests échoués
- Un résumé final avec le nombre de tests réussis

Exemple de sortie :
```
─── ft_strlen ───
✓ ft_strlen: chaîne normale
✓ ft_strlen: chaîne vide
✓ ft_strlen: chaîne longue
✓ ft_strlen: un caractère

Résultat: 225/225 tests réussis
```

### Utiliser le testeur dans votre propre projet

Le testeur peut être adapté pour tester vos propres fonctions. Voici comment :

1. **Copier le fichier de test** :
```bash
cp tests/test_libft.c votre_projet/tests/test_votre_projet.c
```

2. **Modifier le fichier de test** :
   - Remplacez `#include "../libft.h"` par votre header
   - Modifiez les chemins d'inclusion si nécessaire
   - Ajoutez vos propres tests en utilisant la fonction `test()`

3. **Exemple d'ajout de test** :
```c
// Dans votre fichier de test
test("ma_fonction: cas normal", ma_fonction("test") == 4);
test("ma_fonction: chaîne vide", ma_fonction("") == 0);
test("ma_fonction: cas limite", ma_fonction(NULL) == -1);
```

4. **Compiler et exécuter** :
```bash
# Compiler votre bibliothèque
make

# Compiler le testeur
cc -Wall -Wextra -Werror tests/test_votre_projet.c -L. -lft -I. -o test_votre_projet

# Exécuter
./test_votre_projet
```

### Fonction `test()` expliquée

La fonction `test()` prend deux paramètres :
- **Nom du test** : Une description claire de ce qui est testé
- **Résultat** : Une expression booléenne (0 = échec, non-zéro = succès)

```c
void test(const char *name, int result);
```

**Exemple** :
```c
// Test simple
test("ft_strlen: chaîne normale", ft_strlen("hello") == 5);

// Test avec plusieurs conditions
test("ft_isalpha: minuscule", ft_isalpha('a') && ft_isalpha('z'));

// Test avec comparaison
char *s = ft_strdup("test");
test("ft_strdup: duplication", s && !strcmp(s, "test"));
free(s);
```

### Cas limites testés

Le testeur couvre :
- ✅ Chaînes vides `""`
- ✅ Tailles 0
- ✅ Valeurs NULL (quand applicable)
- ✅ Valeurs extrêmes (INT_MAX, INT_MIN)
- ✅ Chevauchements mémoire
- ✅ Buffers trop petits
- ✅ Caractères spéciaux (`\0`, etc.)
- ✅ Cas limites spécifiques à chaque fonction

## 📁 Structure du projet

Le projet est organisé de manière logique par catégories de fonctions :

```
libft/
├── libft.h              # Header principal avec toutes les déclarations
├── Makefile             # Fichier de compilation
├── libft.a              # Bibliothèque compilée
└── src/                 # Tous les fichiers sources organisés
    ├── mem/             # Fonctions de manipulation mémoire
    ├── str/              # Fonctions de manipulation de chaînes (base)
    ├── char/             # Fonctions sur les caractères
    ├── conv/             # Fonctions de conversion
    ├── put/              # Fonctions d'affichage
    ├── str_extra/        # Fonctions avancées sur les chaînes
    └── lst/              # Fonctions de listes chaînées (BONUS)
```

## 📖 Fonctions disponibles

### 🧠 Mémoire (`src/mem/`)
- `ft_memset` - Remplit une zone mémoire avec un octet
- `ft_bzero` - Met à zéro une zone mémoire
- `ft_memcpy` - Copie une zone mémoire
- `ft_memccpy` - Copie jusqu'à trouver un caractère
- `ft_memmove` - Déplace une zone mémoire (gère le chevauchement)
- `ft_memchr` - Recherche un octet dans une zone mémoire
- `ft_memcmp` - Compare deux zones mémoire
- `ft_calloc` - Alloue et initialise une zone mémoire

### 📝 Chaînes de base (`src/str/`)
- `ft_strlen` - Calcule la longueur d'une chaîne
- `ft_strdup` - Duplique une chaîne
- `ft_strlcpy` - Copie une chaîne de manière sécurisée
- `ft_strlcat` - Concatène deux chaînes de manière sécurisée
- `ft_strchr` - Recherche un caractère dans une chaîne
- `ft_strrchr` - Recherche la dernière occurrence d'un caractère
- `ft_strncmp` - Compare deux chaînes sur n caractères
- `ft_strnstr` - Recherche une sous-chaîne dans une chaîne

### 🔤 Caractères (`src/char/`)
- `ft_isalpha` - Vérifie si un caractère est alphabétique
- `ft_isdigit` - Vérifie si un caractère est un chiffre
- `ft_isalnum` - Vérifie si un caractère est alphanumérique
- `ft_isascii` - Vérifie si un caractère est ASCII
- `ft_isprint` - Vérifie si un caractère est imprimable
- `ft_toupper` - Convertit en majuscule
- `ft_tolower` - Convertit en minuscule

### 🔄 Conversion (`src/conv/`)
- `ft_atoi` - Convertit une chaîne en entier
- `ft_itoa` - Convertit un entier en chaîne

### 📤 Affichage (`src/put/`)
- `ft_putchar_fd` - Affiche un caractère sur un file descriptor
- `ft_putstr_fd` - Affiche une chaîne sur un file descriptor
- `ft_putendl_fd` - Affiche une chaîne suivie d'un retour à la ligne
- `ft_putnbr_fd` - Affiche un nombre sur un file descriptor

### ✨ Chaînes avancées (`src/str_extra/`)
- `ft_substr` - Extrait une sous-chaîne
- `ft_strjoin` - Joint deux chaînes
- `ft_strtrim` - Supprime les caractères spécifiés en début/fin
- `ft_split` - Divise une chaîne selon un délimiteur
- `ft_strmapi` - Applique une fonction à chaque caractère (retourne nouvelle chaîne)
- `ft_striteri` - Applique une fonction à chaque caractère (modifie en place)

### 🔗 Listes chaînées - BONUS (`src/lst/`)
- `ft_lstnew` - Crée un nouvel élément de liste
- `ft_lstadd_front` - Ajoute un élément au début de la liste
- `ft_lstadd_back` - Ajoute un élément à la fin de la liste
- `ft_lstsize` - Compte le nombre d'éléments dans la liste
- `ft_lstlast` - Retourne le dernier élément de la liste
- `ft_lstdelone` - Supprime un élément de la liste
- `ft_lstclear` - Supprime tous les éléments de la liste
- `ft_lstiter` - Itère sur la liste et applique une fonction
- `ft_lstmap` - Crée une nouvelle liste en appliquant une fonction


## 🎁 Bonus

Les fonctions bonus (listes chaînées) sont compilées avec la commande `make bonus`. Elles permettent de manipuler facilement des structures de données en liste chaînée.

## 📝 Notes

- Toutes les fonctions suivent la norme 42
- Les fonctions sont compilées avec les flags `-Wall -Wextra -Werror`
- Les fichiers objets sont placés dans le dossier `obj/` (créé automatiquement)
