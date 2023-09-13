int main(){
    //a pointer to a character
    char *ptoc;
    char c = 'A';
    ptoc = &c;

    //an array of 10 integers
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};

    //a reference to an array of 10 integers
    int *ptoint = arr;

    // a pointer to an array of character strings
    char *string_arr[] = {"pratyay","iacs","cpplab"};

    //a pointer to a pointer to a character
    char **pptoc;
    char *ptoc2;
    char b = 'B';
    ptoc2 = &b;
    pptoc = &ptoc2;

    //constant integer
    const int x = 10;

    //pointer to const int 
    const int* ptr;
    ptr = &x;

    //a constant pointer to an integer
    int q = 5;
    int *const p = &q;

    //a constant pointer to a constant double
    const double y = 10.4897;
    const double *const z= &y;

    return 0;
}