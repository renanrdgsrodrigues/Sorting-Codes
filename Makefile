all:
	gcc bubbleSort.c -o bs
	gcc bubbleSortRecursive.c -o bsr
	gcc countingSort.c -o cs
	gcc heapSort.c -o hs
	gcc insertionSort.c -o is
	gcc selectionSort.c -o ss
	gcc mergeSort.c -o ms
	gcc quickSort.c -o qs

runbs:
	./bs

runbsr:
	./bsr

runcs:
	./cs

runhs:
	./hs

runis:
	./is

runss:
	./ss

runms:
	./ms

runqs:
	./qs
clean:
	rm bs bsr cs hs is ss ms qs
