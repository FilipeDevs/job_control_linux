CC = gcc

all: creationGroupe creationSession jobControlDemo obtenirGroupe sighup sighupOrphelins terminalAccess

creationGroupe: creationGroupe.c
	$(CC) -o creationGroupe creationGroupe.c

creationSession: creationSession.c
	$(CC) -o creationSession creationSession.c

jobControlDemo: jobControlDemo.c
	$(CC) -o job jobControlDemo.c

obtenirGroupe: obtenirGroupe.c
	$(CC) -o obtenirGroupe obtenirGroupe.c

sighup: sighup.c
	$(CC) -o sighup sighup.c

sighupOrphelins: sighupOrphelins.c
	$(CC) -o sighupOrphelins sighupOrphelins.c

terminalAccess: terminalAccess.c
	$(CC) -o terminalAccess terminalAccess.c

clean:
	rm -f creationGroupe creationSession job obtenirGroupe sighup sighupOrphelins terminalAccess
