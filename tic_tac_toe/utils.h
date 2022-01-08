#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

bool has(int arr[], int item);

void register_value(int value, int arr[]);

int size(int arr[]);