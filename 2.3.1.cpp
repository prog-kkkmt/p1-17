void reverse(int a[], unsigned size){
    int temp = a[0];
    for(int i = 0; i < size - 1; i++){
        a[i] = a[i+1];
    }
    a[size-1] = temp;
}
void rotate(int a[], unsigned size, int shift){
    shift %= size; // cдвиг
    for(int i = 0; i < shift; i++){
        reverse(a, size);
    }
}
