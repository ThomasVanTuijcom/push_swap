# push_swap

Un projet 42 centré sur l'optimisation d'un tri à l'aide de piles et d'opérations restreintes.

## 🎯 Objectif

Écrire un programme `push_swap` qui trie une pile de nombres entiers en utilisant une deuxième pile et une liste restreinte d'instructions, le tout avec **le moins d’opérations possible**.

Ce projet met l’accent sur :
- La rigueur algorithmique
- La gestion de la mémoire
- L’optimisation des performances
- La complexité algorithmique

---

## 🔧 Instructions

### 🔢 Opérations disponibles

Vous avez deux piles : `a` (initialement remplie) et `b` (initialement vide).

| Commande | Description |
|----------|-------------|
| `sa`     | Swap les deux premiers éléments de `a` |
| `sb`     | Swap les deux premiers éléments de `b` |
| `ss`     | `sa` et `sb` en même temps |
| `pa`     | Push le premier élément de `b` vers `a` |
| `pb`     | Push le premier élément de `a` vers `b` |
| `ra`     | Rotate `a` (le premier devient dernier) |
| `rb`     | Rotate `b` |
| `rr`     | `ra` et `rb` en même temps |
| `rra`    | Reverse rotate `a` (le dernier devient premier) |
| `rrb`    | Reverse rotate `b` |
| `rrr`    | `rra` et `rrb` en même temps |

---

## 🧪 Exemple

```bash
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
