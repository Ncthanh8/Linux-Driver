savedcmd_/home/pi/Linux-Driver/b2-dev-nr/dev_nr.mod := printf '%s\n'   dev_nr.o | awk '!x[$$0]++ { print("/home/pi/Linux-Driver/b2-dev-nr/"$$0) }' > /home/pi/Linux-Driver/b2-dev-nr/dev_nr.mod
