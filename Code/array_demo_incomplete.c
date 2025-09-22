int *array;
int n = 10;

array = (int *) malloc(n * sizeof(int));

for(int i = 0; i < n; i++) {
  array[i] = i + 1;
}

for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
}

n = n * 2;

array = (int *) realloc(array, n * sizeof(int));

for (int i = n/2; i < n; i++) {
    array[i] = i + 1;   // initialize new elements
}
