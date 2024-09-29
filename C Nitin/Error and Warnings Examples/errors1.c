int main() {
    char *str = "Hello";
    int len = sizeof(str);  // Size of pointer instead of string
    printf("Length: %d\n", len);
    return 0;
}
