compileall: compRecMS compIterMS runRecMS_0 runIterMS_0 runRecMS_1 runIterMS_1

compRecMS: main.o merge.o mergeSortRec.o
	gcc -o recMerge main.o mergeSortRec.o merge.o

compIterMS: main.o merge.o mergeSortIter.o
	gcc -o iterMerge main.o mergeSortIter.o merge.o

runRecMS_0: compRecMS
		./recMerge 1024.txt 1024

runIterMS_0: compIterMS
		./iterMerge 1024.txt 1024

runRecMS_1: compRecMS
	./recMerge 10240.txt 10240

runIterMS_1: compIterMS
	./iterMerge 10240.txt 10240

main.o : main.c merge.h
	gcc -c main.c

mergeSortRec.o : mergeSortRec.c merge.h
	gcc -c mergeSortRec.c

mergeSortIter.o : mergeSortIter.c merge.h
	gcc -c mergeSortIter.c

merge.o : merge.c
	gcc -c merge.c
