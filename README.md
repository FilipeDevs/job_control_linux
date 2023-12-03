# Contrôle de Jobs - Filipe PEREIRA MARTINS - 58093 (E11)

## Génération Rapport PDF

Depuis la racine, rendez-vous dans le dossier `report/` :

```bash
cd report
```

Pour générer le rapport en PDF :

```bash
pdflatex main.tex
```

## Compilation des Démonstrations

Depuis la racine, accédez au dossier `demos/` :

```bash
cd demos
```

Compilez les programmes :

```bash
make
```

Nettoyez les programmes compilés :

```bash
make clean
```

### Utilisation

`creationGroupe.c` : Démonstration de la création d'un nouveau groupe.

```bash
./creationGroupe
```

`creationSession.c` : Démonstration de la création d'une nouvelle session et tentative d'ouverture d'un terminal de contrôle.

```bash
./creationSession
```

`obtenirGroupe.c` : Démonstration de l'obtention du groupe d'un processus.

```bash
./obtenirGroupe
```

`sighup.c` : Démonstration du signal SIGHUP. Le programme est destiné à être exécuté avec une redirection vers un fichier de logs. Lors du lancement du programme, fermez le terminal où il s'exécute et consultez les logs pour observer les résultats.

```bash
./obtenirGroupe > logs.log
```

Si un paramètre est donné, le processus fils créé sera placé dans un nouveau groupe.

```bash
./obtenirGroupe x > logs.log
```

`sighupOrphelins.c` : Démonstration du signal SIGHUP dans un cas particulier nommé : groupe de processus orphelin.

```bash
./sighupOrphelins x > logs.log
```

`terminalAccess.c` : Démonstration de l'accès d'un processus au terminal. Le programme est une version simplifiée de `cat`.

```bash
./terminalAccess
```

`jobControlDemo.c` : Démonstration du cycle de vie d'un programme sous le contrôle de jobs. Le programme est destiné à être exécuté dans un pipeline pour illustrer le comportement d'un pipeline au sein du contrôle de jobs. Pour observer le comportement et les sorties, utilisez les commandes et signaux de contrôle de jobs intégrées au shell (fg, bg, CTRL-C, CTRL-Z)

```bash
./job | ./job
```

`scriptBidon.sh` : Simple script qui affiche la date et l'heure courantes toutes les 3 secondes.

# Bibliographie et références

- The Design and Implementation of the FreeBSD Operating System, by Marshall Kirk McKusick, George V. Neville-Neil

* The Linux Programming Interface by Michael KerrisK

* Advanced Programming in the UNIX Environment: Second Edition by W. Richard Stevens, Stephen A. Rago

* The GNU C Library (glibc) manual
