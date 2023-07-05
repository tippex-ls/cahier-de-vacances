//features_names est un tableau de chaînes de caractères contenant les nom des features et input_size est la taille de ce tableau. feature_values est un tableau dont la case i est un tableau de caractères contenant les différentes valeurs possibles pour la feature numéro i. feature_values_size est un tableau d'entier contenant le nombre de valeurs possibles pour chacun des features. On procède de manière similaire pour les classes, mais celles-ci sont simplement codées par un caractère.
struct data_signature_s {char** feature_names; int input_size; char** feature_values; int* feature_values_size; char* class_names; int class_count;};
typedef struct data_signature_s data_signature_t;

struct data_value_s {int id; int* features; int class;}; //La classe et les features sont représentées par leur index. On ajoute un id pour une simplicité de manipulation
typedef struct data_value_s data_value_t;

struct data_set_s {data_value_t** data_array; int size; data_signature_t* signature;}; //On inclue la signature dans le data set, data_array contient directement des pointeurs vers les entrées plutôt que les entrées elles même. Attention à la libération.
typedef struct data_set_s data_set_t;

data_signature_t* read_data_signature(char* signature_filename); //Lit la signature d'un dataset dans un fichier adapté

data_set_t* read_data(char* data_filename, data_signature_t* signature); //lit un fichier de données dont la signature est donnée.

void free_signature(data_signature_t* sig); //libération des nombreux espaces mémoire réservés pour l'occasion

void free_data_set(data_set_t* ds); //Libération d'un data-set et de tous les éléments présents dans celui ci.