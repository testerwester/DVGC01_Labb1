mainmake: parser.c driver.c
	gcc -Wall -c driver.c
	gcc -Wall -c parser.c
	gcc -Wall -o parser driver.c parser.c