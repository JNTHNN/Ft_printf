# ft_printf

**ft_printf** est une réimplémentation de la fonction standard `printf`. Le projet consiste à coder une version simplifiée mais fonctionnelle, capable de gérer plusieurs types et spécificateurs de format.

---

## 🎯 Objectif du projet  
- Comprendre et manipuler les fonctions variadiques en C.  
- Implémenter des mécanismes complexes comme le parsing de spécificateurs de format.  
- Apprendre à produire des sorties formatées tout en optimisant la gestion de la mémoire et des performances.

---

## 🛠️ Compétences clés  
- **Fonctions variadiques** : utilisation des macros `va_start`, `va_arg`, et `va_end` pour traiter un nombre variable d’arguments.  
- **Parsing des spécificateurs** : compréhension et implémentation des formats comme `%d`, `%s`, `%c`, etc.  
- **Manipulation avancée des chaînes** : gestion de l’allocation et de la concaténation de données dynamiques.  
- **Optimisation** : écrire un code efficace et robuste pour minimiser l’utilisation des ressources.

---

## 🚀 Usage  
La fonction se comporte comme suit :  
```c
int ft_printf(const char *format, ...);
```

- **format** : une chaîne contenant du texte ordinaire et des spécificateurs de format (ex. : `%d`, `%s`, `%x`).  
- **Retourne** :  
  - Le nombre total de caractères imprimés (en excluant le caractère nul final).  

### Exemples d’utilisation :
```c
ft_printf("Hello, %s!\n", "world"); // Affiche "Hello, world!"
ft_printf("Valeur : %d\n", 42);     // Affiche "Valeur : 42"
```

---

## 📚 Ressources utilisées  
- Manipulation des fonctions variadiques avec `stdarg.h`.  
- Utilisation de `write` pour produire des sorties.  
- Gestion des chaînes de caractères avec des fonctions maison (pas de bibliothèque standard).  

---

## 🌟 Ce que j’ai appris  
Ce projet m’a permis de développer une compréhension approfondie des points suivants :  
- La mécanique interne de `printf` et la manipulation des arguments multiples.  
- La gestion et la robustesse des sorties formatées en C.  
- L’écriture d’un code propre, modulaire et performant.  

---

## 🖥️ Résultats finaux  
- Une fonction **ft_printf** fonctionnelle, gérant plusieurs types et formats courants (`%c`, `%s`, `%d`, `%x`, etc.).  
- Une maîtrise accrue des concepts avancés en C.

---
